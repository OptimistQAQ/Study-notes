import cv2
import numpy as np
import os
from scipy import ndimage

kernel_3x3 = np.array([[-1, -1, -1],
                       [-1, 8, -1],
                       [-1, -1, -1]])

kernel_5x5 = np.array([[-1, -1, -1, -1, -1],
                       [-1, 1, 2, 1, -1],
                       [-1, 2, 4, 2, -1],
                       [-1, 1, 2, 1, -1],
                       [-1, -1, -1, -1, -1]])

# img = np.zeros((3, 3), dtype=np.uint8)
# img = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
# print(img)

# 参数0表示将图片变为灰色
img = cv2.imread("D:/Program Files (x86)/PychramProjects/python/Picture/1.jpg", 0)
# cv2.imshow("1.jpg", img)
# cv2.waitKey(10000)

# k3 = ndimage.convolve(img, kernel_3x3)
# k5 = ndimage.convolve(img, kernel_5x5)
#
# blurred = cv2.GaussianBlur(img, (11, 11), 0)
# g_hpf = img - blurred
# cv2.imshow("3x3", k3)
# cv2.imshow("5x5", k5)
# cv2.imshow("g_hpf", g_hpf)
# cv2.waitKey()
# cv2.destroyAllWindows()


# 描述边缘轮廓
cv2.imwrite("1.jpg", cv2.Canny(img, 200, 300))
cv2.imshow("canny", cv2.imread("1.jpg"))
cv2.waitKey()
cv2.destroyAllWindows()