import matplotlib.pyplot as plt
import math
import random


def logic(x):
    return 1 / (1 + math.e**(-x))


def f(x, y):
    return (y - logic(x))**2


x_list = []
loss_list = []
for i in range(3000):
    x = random.uniform(-100, 100)
    y = 1 if logic(x) >= 0.5 else 0
    loss = f(x, y)
    x_list.append(x)
    loss_list.append(loss)

plt.scatter(x_list, loss_list)
plt.show()
