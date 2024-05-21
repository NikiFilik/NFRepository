import matplotlib
import matplotlib.pyplot as plt

import numpy as np

import scipy



def task1():
    X = np.linspace(-1, 1, 1000)
    COLORS = [(1, 0, 0), (1, 0.5, 0), (1, 1, 0), (0, 1, 0), (0.5, 0.5, 1), (0, 0, 1), (0.5, 0, 1)]

    for i in range(7):
        plt.plot(X, scipy.special.legendre(i + 1)(X), color = COLORS[i], label = "n=" + str(i + 1))

    plt.legend()
    plt.title("Полиномы Лежандра")
    plt.show()
    


def task2():
    RATIOS = [[[3, 2], [3, 4]], [[5, 4], [5, 6]]]
    figure, axes = plt.subplots(2, 2)
    T = np.linspace(0, 2 * np.pi, 1000)

    for i in range(2):
        for j in range(2):
            X = np.sin(RATIOS[i][j][0] * T)
            Y = np.sin(RATIOS[i][j][1] * T)

            axes[i][j].plot(X, Y)
            axes[i][j].set_title("Ratio: " + str(RATIOS[i][j][0]) + ":" + str(RATIOS[i][j][1]))
    
    plt.tight_layout()
    plt.show()
    


def task3():
    print()
    


def task4():
    print()
    


def task5():
    print()



#task1()
#task2()
task3()
#task4()
#task5()