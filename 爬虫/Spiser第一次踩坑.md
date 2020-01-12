# spider第一次踩坑



**使用urllib.request获取http://www.python.org这个网页**



```python
import urllib.request

# 提供URL/URI
response = urllib.request.urlopen('https://www.python.org')
print(response.read().decode('utf-8'))
```



#### 运行结果



![]( [https://github.com/OptimistQAQ/Study-notes/blob/master/%E7%88%AC%E8%99%AB/%E5%9B%BE%E7%89%87/1.JPG](https://github.com/OptimistQAQ/Study-notes/blob/master/爬虫/图片/1.JPG) )



## 简单获取Github图标

```python
# 简单获取GitHub图标
import requests

r = requests.get("https://github.com/favicon.ico")
# 使用open()的方法，第一个参数是文件名，第二个参数代表以二进制写的形式打开
with open('favicon.ico', 'wb') as f:
    f.write(r.content)
```



# ssl证书验证

```python
# SSL证书验证
import requests
response = requests.get("https://www.12306.cn", verify=False)
print(response.status_code)

/*
***D:\Program Files (x86)\Anaconda\lib\site-***packages\urllib3\connectionpool.py:847: InsecureRequestWarning: Unverified ***HTTPS request is being made. Adding certificate verification is strongly ***advised. See: https://urllib3.readthedocs.io/en/latest/advanced-***usage.html#ssl-warnings
***  InsecureRequestWarning)
***D:\Program Files (x86)\Anaconda\lib\site-***packages\urllib3\connectionpool.py:847: InsecureRequestWarning: Unverified ***HTTPS request is being made. Adding certificate verification is strongly ***advised. See: https://urllib3.readthedocs.io/en/latest/advanced-***usage.html#ssl-warnings
***  InsecureRequestWarning)
***200
*/
```



# 正则——常用匹配规则

|  模式  |                           描述                           |
| :----: | :------------------------------------------------------: |
|   \w   |                  匹配字母、数字及下划线                  |
|   \W   |           匹配不是字母、数字及下划线的其他字符           |
|   \s   |            匹配任意空白字符，等价于[\t\n\r\f]            |
|   \S   |                    匹配任意非空白字符                    |
|   \d   |                匹配任意数字，等价于[0-9]                 |
|   \D   |                   匹配任意非数字的字符                   |
|   \A   |                      匹配字符串开头                      |
|   \Z   | 匹配字符串结束，如果存在换行，只匹配到换行前的结束字符串 |
|   \n   |                      匹配一个换行符                      |
|   \t   |                      匹配一个制表符                      |
|   *    |                   匹配0个或多个表达式                    |
|  {n}   |                 精确匹配n个前面的表达式                  |
| {n, m} |      匹配n到m次由前面正则表达式定义的片段，贪婪方式      |
|  （）  |             匹配括号内的表达式，也表示一个组             |



#  爬取猫眼电影评分等



```python
import requests
import json
from requests.exceptions import RequestException
import re
import time


def get_one_page(url):
    try:
        headers = {
            # 'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko)
            # Chrome/79.0.3945.117 Safari/537.36'
            'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.162 Safari/537.36'
        }
        response = requests.get(url, headers=headers)
        if response.status_code == 200:  # 表示访问成功
            return response.text
        return None
    # 处理异常
    except RequestException:
        return None

# 抓取一页
def parse_one_page(html):
    # 正则表达式获取需要信息
    pattern = re.compile('<dd>.*?board-index.*?>(\d+)</i>.*?data-src="(.*?)".*?name"><a'
                         + '.*?>(.*?)</a>.*?star">(.*?)</p>.*?releasetime">(.*?)</p>'
                         + '.*?integer">(.*?)</i>.*?fraction">(.*?)</i>.*?</dd>', re.S)
    items = re.findall(pattern, html)
    for item in items:
        yield {
            'index': item[0],
            'image': item[1],
            'title': item[2],
            'actor': item[3].strip()[3:],
            'time': item[4].strip()[5:],
            'score': item[5] + item[6]
        }

# 写入文件
def write_to_file(content):
    with open('result.txt', 'a+', encoding='utf-8') as f:
        f.write(json.dumps(content, ensure_ascii=False, indent=2) + '\n')


def main(offset):
    url = 'http://maoyan.com/board/4?offset=' + str(offset)
    html = get_one_page(url)
    for item in parse_one_page(html):
        print(item)
        write_to_file(item)

if __name__ == '__main__':
    for i in range(10):
        main(offset=i * 10)
        # 设置延迟
        time.sleep(1)
```



**获取的已保存在result。txt中**



#  获取豆瓣电影相关信息

```python
import requests
import re
import json
from lxml import etree

url = "https://movie.douban.com/cinema/nowplaying/changzhi/"

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.90 Safari/537.36",
    "Host": "movie.douban.com"
}
response = requests.get(url, headers=headers)
html_str = response.content.decode()
html = etree.HTML(html_str)

div_list = html.xpath("//div[@id='nowplaying']/div[@class='mod-bd']/ul/li//li[@class='poster']/a/@href")
for movie_url in div_list:
    movie_response = requests.get(movie_url, headers=headers)
    movie_html_str = movie_response.content.decode()
    movie_info = {}
    movie_html = etree.HTML(movie_html_str)
    div1_list = movie_html.xpath("//div[@id='content']")
    for div in div1_list:
        movie_info["title"] = div.xpath("./h1/span[@property='v:itemreviewed']/text()")
        movie_info["director"] = div.xpath(".//div[@id='info']/span/span[2]//text()")[0]
        movie_info["introduction"] = div.xpath(".//div[@class='indent']/span/text()")[0].strip()
        recommendations_names = div.xpath(
            ".//div[@id='recommendations']/div[@class='recommendations-bd']/dl/dd/a/text()")
        recommendations_url = div.xpath(".//div[@id='recommendations']/div[@class='recommendations-bd']/dl/dt/a/@href")
        movie_info["recommendations"] = {name: url for name in recommendations_names for url in recommendations_url}
    comment_url = (re.findall("https://.+/", movie_url)[0]) + "comments?status=P"
    comment_response = requests.get(comment_url, headers=headers)
    comment_str = comment_response.content.decode()
    comment = etree.HTML(comment_str)
    content_text = comment.xpath("//div[@class='comment-item']/div[@class='comment']/p/span/text()")
    comment_vote = comment.xpath("//div[@class='comment-item']/div[@class='comment']//span[@class='votes']/text()")
    movie_info["comments"] = {text: vote for text in content_text for vote in comment_vote}
    with open("moive.txt", "a+", encoding="utf-8") as f:
        f.write(json.dumps(movie_info, ensure_ascii=False, indent=2))
        f.write("\n")
    print(movie_info["title"], "保存成功")
```



**已保存在movie.txt中**

