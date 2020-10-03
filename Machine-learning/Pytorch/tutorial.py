import torch
import torch.nn.functional as F
from torch.autograd import Variable
import matplotlib.pyplot as plt

# # fake data
# x = torch.linspace(-5, -5, 200)  # x data (tensor), shape=(100, 1)
# x = Variable(x)
# x_np = x.data.numpy()
#
# y_relu = F.relu(x).data.numpy()
# # y_sigmoid = F.sigmoid(x).data.numpy()
# # y_tanh = F.tanh(x).data.numpy()
# y_softplus = F.softplus(x).data.numpy()
#
# plt.figure(1, figsize=(8, 6))
# plt.subplot(221)
# plt.plot(x_np, y_relu, c='red', label='relu')
# plt.ylim((-1, 5))
# plt.legend(loc='best')
# plt.show()
#
# # plt.subplot(222)
# # plt.plot(x_np, y_sigmoid, c='red', label='sigmoid')
# # plt.ylim((-0.2, 1.2))
# # plt.legend(loc='best')
# # plt.show()
# #
# # plt.subplot(223)
# # plt.plot(x_np, y_tanh, c='red', label='tanh')
# # plt.ylim((-1.2, 1.2))
# # plt.legend(loc='best')
# # plt.show()
#
# plt.subplot(224)
# plt.plot(x_np, y_softplus, c='red', label='softplus')
# plt.ylim((-0.2, 6))
# plt.legend(loc='best')
# plt.show()

x = torch.unsqueeze(torch.linspace(-1, 1, 100), dim=1)
y = x.pow(2) + 0.2 * torch.rand(x.size())

x, y = Variable(x), Variable(y)

# plt.scatter(x.data.numpy(), y.data.numpy())
# plt.show()

# pytorch神经网络搭建
class Net(torch.nn.Module):

    def __init__(self, n_feature, n_hidden, n_output):
        super(Net, self).__init__()
        self.hidden = torch.nn.Linear(n_feature, n_hidden)  # 隐藏层
        self.predict = torch.nn.Linear(n_hidden, 1)  # 预测

    def forward(self, x):
        x = F.relu(self.hidden(x))
        x = self.predict(x)
        return x

net = Net(1, 10, 1)
print(net)

plt.ion()
plt.show()

optimizer = torch.optim.SGD(net.parameters(), lr=0.5)
loss_func = torch.nn.MSELoss()

for t in range(100):
    prediction = net(x)

    loss = loss_func(prediction, y)

    optimizer.zero_grad()
    loss.backward()
    optimizer.step()

    if t % 5 == 0:
        # plot and show learning process
        plt.cla()
        plt.scatter(x.data.numpy(), y.data.numpy())
        plt.plot(x.data.numpy(), prediction.data.numpy(), 'r-', lw=5)
        plt.text(0.5, 0, 'Loss=%.4f' % loss.item(), fontdict={'size': 20, 'color': 'red'})
        plt.pause(0.1)

plt.ioff()
plt.show()