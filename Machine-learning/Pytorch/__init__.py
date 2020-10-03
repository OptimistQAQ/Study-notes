import torch
import numpy as np
from torch.autograd import Variable


# np_data = np.arange(6).reshape((2, 3))
# torch_data = torch.from_numpy(np_data)
# tensor2array = torch_data.numpy()
#
# print(
#     '\nnumpy', np_data,
#     '\ntorch', torch_data,
#     '\ntensor2array', tensor2array
# )


# # abs 绝对值
# data = [-1, -2, 1, 2, 0]
# tensor = torch.FloatTensor(data)   # 32bit
# print(
#     'sin',
#     '\nnumpy', np.sin(data),
#     '\ntorch', torch.sin(tensor)
# )

# # 矩阵形式
# data = [[1, 2], [3, 4]]
# tensor = torch.FloatTensor(data)
# print(
#     '\nnumpy', np.matmul(data, data),
#     '\ntensor', torch.mm(tensor, tensor)
# )

tensor = torch.FloatTensor([[1, 2], [3, 4]])
variable = Variable(tensor, requires_grad=True)

t_out = torch.mean(tensor*tensor)  # x^2
v_out = torch.mean(variable*variable)


print(t_out)
print(v_out)

v_out.backward()
print(variable.grad)
print(variable.data)
print(variable.data.numpy())