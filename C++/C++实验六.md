# C++实验六

[TOC]

## 实验名称

> **面向对象程序设计综合设计**

## 实验题目

> *创建简单的二维“捕食者-被捕食者”模拟程序。被捕食者是蚂蚁（ant），捕食者是狮蚁（doodlebug）。这些小生物生活在20×20的网格世界中。每个单元格每次只能由一个个体占据。网格是封闭的，所以个体不允许离开网格世界边缘。时间以time step为单位，个体在每个time step里面都要采取某项行动。具体规则如下：*
>
> ***1****． 建立蚂蚁的行为规则模型。***
>
> *（1）Move（移动）：在每个time step中，都随机向上、向下、向左或者向右移动。假如所选方向上的邻居单元格被占据，或者会造成蚂蚁移动到网格的边缘之外，那么蚂蚁就停留在当前的单元格中。*
>
> *（2）Breed（繁殖）：如果一只蚂蚁在3个time step中保存存活，在第3个time step结束之后（也就是在移动之后），该蚂蚁会繁殖。为了模拟繁殖，需要在相邻（上、下、左或者右）的一个空单元格中创建一只新蚂蚁。没有可用的空单元格，就不会繁殖。一旦成功繁殖出后代，除非再次经历3个time step，否则不能繁殖另一个后代。*
>
> ***2.** **建立狮蚁的行为规则模型。***
>
> *（1）Move（移动）：在每个time step中，假如有一只相邻的蚂蚁（上、下、左或者右），就移动到那个单元格，吃掉蚂蚁。否则，狮蚁就按照和蚂蚁相同的规则移动。注意，狮蚁不能吃掉狮蚁。*
>
> *（2）Breed（繁殖）：假如一只狮蚁在8个time step中保持存活，在第8个time step结束之后，会按照与蚂蚁相同的方式繁殖出一只新狮蚁。*
>
> *（3）Starve（饥饿）：假如一只狮蚁在连续3个time step中没有吃掉一只蚂蚁，在第3个time step结束之后，它会感到饥饿并死亡。该狮蚁应从网格中拿掉。*
>
> *（4）在一轮中，所有狮蚁都应该先于蚂蚁移动。*
>
> ***3.** **编写主程序来模拟“捕食者-被捕食者”游戏。***
>
> *（1）使用ASCII字符“o”表示蚂蚁，“x”表示狮蚁。创建名为Organism（有机生物）的类，它封装了通用于蚂蚁和狮蚁的基本数据。该类应该有一个名为Move的virtual函数，它要在派生类Ant和Doodlebug中进行具体的定义。可能需要额外的数据结构来跟踪已移动的生物。*
>
> *（2）使用5只狮蚁和100只蚂蚁初始化这个网格世界。在每个time step后，都提示用户按Enter键移动到下一个time step。应该看到狮蚁和蚂蚁数量的循环变化——虽然一些随机性的混乱可能造成一种或两种生物的毁灭。*

## 源代码

```c++
struct Step
{
	int dx;
	int dy;
};

enum AnimalType
{
	IsAnt,
	IsDoodlebug
};

class Organism;
class Cell
{
public:
	int x;
	int y;
	Organism *animal;

public:
	Cell(int x0, int y0);
	Cell *nearbyCell(int dir);
	bool in(Organism *animal0);
	Organism *leave();
};

class Organism
{
protected:
	int maxBreedTime;
	int breedTime;
	int maxStarveTime;
	int starveTime;
public:
	AnimalType type;
	Organism *next;
	Organism *prior;
public:
	Organism();
	virtual ~Organism();

public:
	virtual Organism *breedChild() = 0;
	virtual bool canEat(AnimalType animal) = 0;
	virtual bool eat() = 0;

public:
	Cell *cell;
	bool breed();
	virtual bool move();
	void step();
};

class Ant :public Organism
{
public:
	Ant();
public:
	virtual Organism *breedChild();
	virtual bool canEat(AnimalType t);
	virtual bool eat();
};

class Doodlebug :public Organism
{
public:
	Doodlebug();
public:
	virtual Organism *breedChild();
	virtual bool canEat(AnimalType t);
	virtual bool eat();
};

Step Steps[4] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
int maxWidth;
int maxHeight;
Cell ***Status;
Organism *DoodleBugs;
Organism *Ants;


Cell::Cell(int x0, int y0)
{
	this->x = x0;
	this->y = y0;
	this->animal = NULL;
}
Cell *Cell::nearbyCell(int dir)
{
	int x0 = this->x + Steps[dir].dx;
	int y0 = this->y + Steps[dir].dy;
	if (x0 < 0 || y0 < 0 || x0 >= maxWidth || y0 >= maxHeight)
		return NULL;
	else
	{
		return Status[x0][y0];
	}
}
bool Cell::in(Organism *animal0)
{
	if (this->animal != NULL)
		return false;
	else
	{
		animal0->cell = this;
		this->animal = animal0;
		return true;
	}
}
Organism *Cell::leave()
{
	Organism *theAnimal = this->animal;
	theAnimal->cell = NULL;
	this->animal = NULL;
	return theAnimal;
}

Organism::Organism()
{
	this->cell = NULL;
	this->breedTime = 0;
	this->starveTime = 0;

	this->prior = NULL;
	this->next = NULL;
}
bool Organism::breed()
{
	if (this->breedTime >= maxBreedTime)
	{
		for (int i = 0; i < 4; i++)
		{
			Cell *c = this->cell->nearbyCell(i);
			if (c != NULL && c->animal == NULL)
			{
				c->in(this->breedChild());
				this->breedTime = 0;
				return true;
			}
		}
	}
	return false;
}
bool Organism::move()
{
	int dir = rand() % 4;
	Cell *c = this->cell->nearbyCell(dir);
	if (c == NULL)
		return false;
	else if (c->animal == NULL)
	{
		c->in(this->cell->leave());
		return true;
	}
}
void Organism::step()
{
	bool dosth = false;
	this->breedTime++;
	this->starveTime++;

	dosth |= this->breed();
	dosth |= this->eat();
	if (!dosth)
	{
		this->move();
	}

	if (this->maxStarveTime > 0 && this->starveTime >= this->maxStarveTime)
	{
		//starve
		this->cell->leave();
		delete (this);
	}
}
Organism::~Organism()
{
	Organism *t = this->next;
	this->prior->next = t;
	if (t != NULL)
		t->prior = this->prior;
}

Ant::Ant() : Organism()
{
	this->type = IsAnt;
	this->maxStarveTime = -1;
	this->maxBreedTime = 3;

	if (Ants != NULL)
	{
		this->prior = Ants;
		this->next = Ants->next;
		if (Ants->next != NULL) Ants->next->prior = this;
		Ants->next = this;
	}
}
Organism *Ant::breedChild()
{
	return new Ant();
}
bool Ant::canEat(AnimalType t)
{
	return false;
}
bool Ant::eat()
{
	return false;
}

Doodlebug::Doodlebug() :Organism()
{
	this->type = IsDoodlebug;
	this->maxStarveTime = 3;
	this->maxBreedTime = 8;

	if (DoodleBugs != NULL)
	{
		this->prior = DoodleBugs;
		this->next = DoodleBugs->next;
		if (DoodleBugs->next != NULL) DoodleBugs->next->prior = this;
		DoodleBugs->next = this;
	}
}
Organism *Doodlebug::breedChild()
{
	return new Doodlebug();
}
bool Doodlebug::canEat(AnimalType t)
{
	if (t == IsAnt)
		return true;
	else
		return false;
}
bool Doodlebug::eat()
{
	for (int i = 0; i < 4; i++)
	{
		Cell *c = this->cell->nearbyCell(i);
		if (c != NULL && c->animal != NULL && this->canEat(c->animal->type))
		{
			Organism *theAnimal = c->leave();
			delete(theAnimal);
			this->starveTime = 0;
			return true;
		}
	}
	return false;
}

void randomSet(Organism *animal0)
{
	srand(0);
	int x;
	int y;
	do
	{
		x = rand() % maxWidth;
		y = rand() % maxHeight;
	} while (Status[x][y]->animal != NULL);
	Status[x][y]->in(animal0);
}
void  printoutHead()
{
	printf("=");
	for (int i = 0; i < maxWidth; i++)
	{
		printf("=");
	}
	printf("=\n");
}
void printoutDetail(int r)
{
	printf("|");
	for (int i = 0; i < maxWidth; i++)
	{
		if (Status[i][r]->animal == NULL)
			printf(" ");
		else
		{
			switch (Status[i][r]->animal->type)
			{
			case IsAnt:
				printf("O");
				break;
			case IsDoodlebug:
				printf("X");
				break;
			default:
				printf("?");
				break;
			}
		}
	}
	printf("|\n");
}
void printout()
{
	printoutHead();
	for (int i = 0; i < maxHeight; i++)
		printoutDetail(i);
	printoutHead();
}
int main()
{
	int nDoodleBug;
	int nAnt;

	printf("请输入区域宽度：");
	scanf("%d", &maxWidth);
	printf("请输入区域高度：");
	scanf("%d", &maxHeight);
	printf("请输入初始狮蚁数量：");
	scanf("%d", &nDoodleBug);
	printf("请输入初始蚂蚁数量：");
	scanf("%d", &nAnt);

	Status = new Cell**[maxWidth];
	DoodleBugs = new Doodlebug();
	Ants = new Ant();

	for (int i = 0; i < maxWidth; i++)
	{
		Status[i] = new Cell*[maxHeight];
		for (int j = 0; j < maxHeight; j++)
		{
			Status[i][j] = new Cell(i, j);
		}
	}

	for (int i = 0; i < nDoodleBug; i++)
	{
		randomSet(new Doodlebug());
	}
	for (int i = 0; i < nAnt; i++)
	{
		randomSet(new Ant());
	}

	printout();
	system("pause");
	while (true)
	{
		Organism *a = DoodleBugs->next;
		Organism *a0;
		for (a0 = (a == NULL ? NULL : a->next); a != NULL; a = a0, a0 = (a == NULL ? NULL : a->next))
			a->step();
		a = Ants->next;
		for (a0 = (a == NULL ? NULL : a->next); a != NULL; a = a0, a0 = (a == NULL ? NULL : a->next))
			a->step();
		system("cls");
		printout();
		system("pause");
	}
	return 0;
}
```

