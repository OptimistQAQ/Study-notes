#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAXSIZE = 100;

typedef struct {
	char str[MAXSIZE];
	int len;
}seqstring;

typedef struct node {
	char data;
	struct node * next;
}linkstring;

//初始化
void strCreat(linkstring *s)
{
	char ch;
	linkstring *p, *r;
	s = NULL;
	r = NULL;
	while ((ch = getchar()) != '\n') {
		p = (linkstring *)malloc(sizeof(linkstring));
		p->data = ch;
		if (s == NULL)
			s = p;
		else r->next = p;
 		r = p;
	}
	if (r != NULL)
		r->next = NULL;
}

//插入运算
void stringsert(seqstring *s, int i, seqstring t)
{
	int k;
	if (i<1 || i>s->len - 1 || s->len + t.len > MAXSIZE - 1)
		printf("can not insert!\n");
	else
	{
		for (k = s->len - 1; k >= i - 1; k--)
			s->str[t.len + k] = s->str[k];
		for (k = 0; k < t.len; k++)
			s->str[i + k - 1] = t.str[k];
		s->len = s->len + t.len;
		s->str[s->len] = '\0';
	}
}

//顺序串删除
void strdel(seqstring *s, int i, int len)
{
	int k;
	if (i<1 || i>s->len || i + len - 1 > s->len)  //非法情况
		printf("cannot deleate\n");
	else
	{
		for (k = i + len - 1; k < s->len; k++)
			s->str[k - len] = s->str[k];
		s->len = s->len - len;
		s->str[s->len] = '\0';
	}
}

//比较两个字符串的大小
int strcompare(seqstring s1, seqstring s2)
{
	int i;
	for (i = 0; i < s1.len && i < s2.len; i++)
	{
		if (s1.str[i] > s2.str[i])
			return 1;
		else if (s1.str[i] < s2.str[i])
			return -1;
		else
			continue;
	}
	return 0;
}

//链式结构
int compare1(linkstring *s3, linkstring *s4) {
	while (s3 && s4) {
		if (s3->data > s4->data)
			return 1;
		else if (s3->data < s4->data)
			return -1;
		s3 = s3->next;
		s4 = s4->next;
	}
	if(s3)
		return 1;
	else if(s4)
		return -1;
	else
		return 0;
}


int main()
{
	seqstring s1, t1;
	int m;

	printf("顺序存储下的比较：\n");
	printf("input:\n");
	scanf("%s%s", s1.str, t1.str);
	s1.len = strlen(s1.str);
	t1.len = strlen(t1.str);
	m = strcompare(s1, t1);
	if (m == 1)
		printf("s1大\n");
	else if (m == 0)
		printf("一样大\n");
	else
		printf("s2大\n");

	int com;
	printf("链式存储下比较：\n");
	printf("input:\n");
	getchar();
	linkstring *s2, *t2;
	s2 = NULL;
	t2 = NULL;
	strCreat(s2);
	strCreat(t2);
	com = compare1(s2, t2);
	if ( com == 1)
		printf("s1大\n");
	else if (com == 0)
		printf("一样大\n");
	else
		printf("s2大\n");
	return 0;
}