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
