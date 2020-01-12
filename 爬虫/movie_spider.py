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