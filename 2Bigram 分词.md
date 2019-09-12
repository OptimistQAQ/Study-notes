## 2:Bigram 分词   
**c++**


#### 分析：
	Bigram 分词的规则，通俗一点讲，就可以这样理解。就是说：对于first的单词，就返回它后面的后面的单词。
	要是没有那个单词就不返回，对于second的单词，就返回它后面的那个单词，同理，要是没有则不返回。
	另外，每一个单词只能使用一次。
	返回以后要将那个单词删除。鉴于此：应该使用vector动态数组存储单词。

**用for循环将string类型的句子用vector数组存起来**

```
text+=' ';
vector<string> stext,res;    //定义String类的vector数组
for(int i=0;i<text.size();i++){
    if(text[i]==' ') {
        stext.push_back(s);  //  在stext的末尾插入单词
        s=""; 
    }else {
        s+=text[i];
    }
}
```
**储存完以后判断**

	      //如果不够三个单词则直接返回  res  
	if(stext.size()<3) return res;

根据规则用 for循环  遍历vector数组中的内容（vector是动态数组，动态分配存储空间，这也是用vector数组的原因），然后将res返回

```
old1=stext[0],old2=stext[1];
for(int i=2;i<stext.size();i++){
   if(old1==first&&old2==second) res.push_back(stext[i]);
   old1=old2;
   old2=stext[i];
}
return res;
```
