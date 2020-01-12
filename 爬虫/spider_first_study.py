import urllib.request

# # 提供URL/URI
# response = urllib.request.urlopen('https://www.python.org')
# print(response.read().decode('utf-8'))

# # print(type(response))
#
# # print(response.status)
# # print(response.getheaders())
# # print(response.getheader('Server'))
#
#

# # 简单获取GitHub图标
# import requests
#
# r = requests.get("https://github.com/favicon.ico")
# # 使用open()的方法，第一个参数是文件名，第二个参数代表以二进制写的形式打开
# with open('favicon.ico', 'wb') as f:
#     f.write(r.content)

# # requests可以模拟提交一些数据,由于该URL不存在，所以会报错
# import requests
# files = {'file', open('favicon.ico', 'rb')}
# r = requests.post("http://httpbin.org/post", files=files)
# print(r.text)

# 使用requests处理Cookies

# import requests
# headers = {
#     'Cookie': '_zap=6f948e8f-d8d8-4880-bef0-b20e9140a0ab; _xsrf=635417ac-dcb4-48a3-a24e-1117ee7d65e3; d_c0="AOCm7zPoNBCPToQbCKHh0ezDyLbIuO-fReg=|1571208438"; Hm_lvt_98beee57fd2ef70ccdd5ca52b9740c49=1578795462; capsion_ticket="2|1:0|10:1578795462|14:capsion_ticket|44:NzIzNjE4N2ZhZDBmNDI3OGIwOWVlZTNlMmRiZmM4YjU=|300d9a5a587626e33036c3c7d6cbdd5ea5707ad78d5bbd60ef6d240f1b8a4dfb"; l_n_c=1; n_c=1; l_cap_id="NjU1MjhkNWI3OWY2NGNkODgxZDJlOGRiMWQ5MTBkN2I=|1578795654|9a3d1be6042d66cd4bfc87edfeaa19df25a04571"; r_cap_id="ZDNmN2M5NWVlYmVlNDAzZmFlOTU4YTMxMjlmOTYyOTI=|1578795654|916b0801f1fef96abc97e1043f578edb55b02bb5"; cap_id="NGM4YjkzYTBjZDdiNDhhNmE4NWY0OTg1NTZhYmQ5Y2E=|1578795654|d6f85348e0031bbe729896e1714958fa184dd939"; z_c0=Mi4xYlVVNUR3QUFBQUFBNEtidk0tZzBFQmNBQUFCaEFsVk5qTkFIWHdBazFvU3M3UEVlY05hTUVoMWoxdi1Ja2xmOURB|1578795660|0b474b99d64c54ad1c5bac8035a3bcf0acbb965c; Hm_lpvt_98beee57fd2ef70ccdd5ca52b9740c49=1578795662; tst=r; KLBRSID=53650870f91603bc3193342a80cf198c|1578795662|1578795461',
#     'Host': 'www.zhihu.com',
#     'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.117 Safari/537.36',
# }
# r = requests.get("https://wwww.zhihu.com", headers=headers)
# print(r.text)

# SSL证书验证
import requests
response = requests.get("https://www.12306.cn", verify=False)
print(response.status_code)
