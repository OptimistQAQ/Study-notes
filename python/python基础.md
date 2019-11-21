# 列表

+ 列表是什么？
  + 访问列表元素
  + 使用列表中的各个值
+ 修改、添加和删除元素
+ 组织列表
  + 使用sort()对列表进行排序
  + 使用sorted()对列表进行排序
+ 遍历整个列表
+ 创建数值列表
  + 使用函数range()
+ 切片
+ 元组
+ 字典
  + 一个简单的字典
  + 遍历字典
  + 嵌套
    + 字典列表
    + 在字典中存储列表
    + 在字典中存储字典

## 列表是什么？

**列表由一系列特定顺序排列的元素组成的。在python中用 [] 来表示列表，并用 , 来分隔其中的元素。**

```python
bicycles = ['trek', 'cannondale', 'specialized']
print(bicycles)
```

### 访问列表元素

访问bicycles中的第一个元素

`print(bicycles[0])`

可以使用title()方法让元素的格式更整洁

`print(bicycles[0].title())`

**注意：在python中，第一个元素的索引为0，而不是1**

### 使用列表中的各个值

可以像其他变量一样使用列表中的各个值。例如：

```python
message = "My first bicycle was a " + bicycles[0].title() + "."
print(message)

### My first bicycle was a Trek.
```

### 修改、添加和删除元素

在python中创建的大多数列表都是动态的，这意味着可以随意地对列表进行修改、删除和添加。

例如：

1. 修改元素的值
   ```python
    bicycles = ['trek', 'cannondale', 'specialized']
    print(bicycles)
    bicycles[0] = 'trak'
    print(bicycles)

    ### ['trek', 'cannondale', 'specialized']
    ### ['trak', 'cannondale', 'specialized']
   ```
2. 添加元素
    1. 在列表的末尾添加元素
        
        **使用append()方法**
        ```python
        bicycles = ['trek', 'cannondale', 'specialized']
        print(bicycles)
        bicycles.append('ducati')
        print(bicycles)

        ### ['trek', 'cannondale', 'specialized']
        ### ['trek', 'cannondale', 'specialized', 'ducati']
        ```
    2. 在列表中插入元素

        **使用insert()方法**

        ```python
        bicycles = ['trek', 'cannondale', 'specialized']
        print(bicycles)
        bicycles.insert(0, 'ducati')
        print(bicycles)


        ### ['trek', 'cannondale', 'specialized']
        ### ['ducati', 'trek', 'cannondale', 'specialized']
        ```
3. 删除元素
   1. 如果要知道删除元素的位置，可以使用del语句删除元素
        ```python
        bicycles = ['trek', 'cannondale', 'specialized']
        print(bicycles)
        del bicycles[0]
        print(bicycles)

        ### ['trek', 'cannondale', 'specialized']
        ### ['cannondale', 'specialized']
        ```
    2. 使用pop方法删除元素
       
       有时候，你需要将元素从列表中删除，并接着使用它的值。

       ```python
       bicycles = ['trek', 'cannondale', 'specialized']
       print(bicycles)
       popped_bicycles = bicycles.pop()
       print(popped_bicycles)

       ### ['trek', 'cannondale', 'specialized']
       ### specialized
       ```

       实际上，可以使用pop()来删除列表中的任何位置的元素，只需要在括号中指定要删除的元素的索引即可。

# 组织列表

## 使用sort()方法对列表进行排序

在创建的列表中，元素的排列顺序通常是无法预测的，所以可以用sort()方法进行排序。

```python
bicycles = ['trek', 'cannondale', 'specialized']
print(bicycles)
bicycles.sort()
print(bicycles)

### ['trek', 'cannondale', 'specialized']
### ['cannondale', 'specialized', 'trek']
```
## 使用sorted()进行临时排序

要保留元素原来的排列顺序，同时以特定的顺序将他们呈现出来，可以使用函数sorted()。

```python
bicycles = ['trek', 'cannondale', 'specialized']
print("Here is the original list:")
print(bicycles)
print("\nHere is the sorted list:")
print(sorted(bicycles))
print("\nHere is the original list again:")
print(bicycles)

##########
## Here is the original list:
## ['trek', 'cannondale', 'specialized']

## Here is the sorted list:
## ['cannondale', 'specialized', 'trek']

## Here is the original list again:
## ['trek', 'cannondale', 'specialized']
```

# 遍历整个列表

```python
bicycles = ['trek', 'cannondale', 'specialized']
for bicycle in bicycles:
    print(bicycle)

##  trek
##  cannondale
##  specialized
```

上面这段代码，我们定义了一个for循环，这行代码让Python从列表bicycles中取出一个名字，并将其存储在bicycle中。然后将其打印出来。输出其中的所有的名字。

# 创建数值列表

## 使用函数range()

```python
for value in range(1, 5):
    print(value)

## 1
## 2
## 3
## 4
```

这个示例打印了1—4，这里不包含5.

```python
numbers = list(range(2, 11, 2))
print(numbers)

## [2, 4, 6, 8, 10]
```

这个示例表示创建列表，列表从2开始，然后不断加2，直到达到或超过最终值，因此最后一个输出结果为10.

# 切片

要创建切片，可以指定要使用的第一个元素和最后一个元素的索引。例如：要输出列表的前三个元素，可指定索引0:3.

```python
bicycles = ['trek', 'cannondale', 'specialized', 'qin']
for bicycle in bicycles[0:3]:
    print(bicycle)

## trek
## cannondale
## specialized
```

上面的例子中使用for循环遍历了bicycles列表中的前三个元素，切片可以指定列表中的任意位置。

# 元组

列表非常适用于存储在程序运行期间可能变化的数据集。列表是可以修改的，这对处理网站的用户列表至关重要。然而，有时候需要创建一系列不可修改的元素，元组可以实现这种操作。

**元组的定义方法是圆括号 ()**

```python
dimensions = (200, 50)
print(dimensions[0])
print(dimensions[1])

## 200
## 50
```

元组的值不可修改

`dimensions[0] = 250`

这句话会报错。

```python
Traceback (most recent call last):
  File "D:/Program Files (x86)/PychramProjects/python/python_space.py", line 48, in <module>
    dimensions[0] = 250
TypeError: 'tuple' object does not support item assignment
```

**虽然不能修改元组的元素的值，但是可以给存储的元组的变量赋值。因此，如果要修改前诉矩阵的尺寸，可以重新定义整个元组**

```python
dimensions = (200, 50)
print(dimensions[0])
print(dimensions[1])
dimensions = (400, 200)
print(dimensions[0])
print(dimensions[1])

## 200
## 50
## 400
## 200
```

# 字典（与 Json类似）

在python中，字典是一系列键—值对。每个键都与一个值相对应，可以使用键来访问值。和C++中的map很相似。下面是一个简单的字典。

```python
# 字典的练习
alien_0 = {'color': 'green', 'points': '5'}
print(alien_0['color'])
print(alien_0['points'])

## green
## 5
```

同时，也可以在已经建好的字典里面添加键值对。例如：

```python
alien_0 = {'color': 'green', 'points': '5'}
print(alien_0)
alien_0['x_position'] = 0
alien_0['y_position'] = 25
print(alien_0)

## {'color': 'green', 'points': '5'}
## {'color': 'green', 'points': '5', 'x_position': 0, 'y_position': 25}
```

**字典中的值是可以修改的。**

### 使用 del 函数删除键值对

```python
del alien_0['points']
```

## 还有各种嵌套结构，多层嵌套，列表套列表，列表套元组，字典套字典等等等等，在这里就不过多赘述了，原理是一样的。

# python