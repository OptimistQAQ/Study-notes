import numpy as np
from matplotlib import pyplot as plt

x = np.arange(1, 11)
y = 2 * x + 5

plt.title("matplotlib demo")
plt.xlabel("X")
plt.ylabel("Y")

plt.plot(x, y, "ob")
plt.show()

for value in range(1, 5):
    print(value)

numbers = list(range(2, 11, 2))
print(numbers)

bicycles = ['trek', 'cannondale', 'specialized', 'qin']
for bicycle in bicycles[0:3]:
    print(bicycle)

print(bicycles)
bicycles.sort()
print(bicycles)

popped_bicycles = bicycles.pop()
print(popped_bicycles)

del bicycles[0]
print(bicycles)
bicycles.insert(0, 'ducati')
print(bicycles)
bicycles[0] = 'trak'
print(bicycles)

print(bicycles[0].title())

message = "My first bicycle was a " + bicycles[0].title() + "."
print(message)

# 元组的练习

dimensions = (200, 50)
print(dimensions[0])
print(dimensions[1])
dimensions = (400, 200)
print(dimensions[0])
print(dimensions[1])


# 字典的练习
alien_0 = {'color': 'green', 'points': '5'}
print(alien_0)
alien_0['x_position'] = 0
alien_0['y_position'] = 25
print(alien_0)