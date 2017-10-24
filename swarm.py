import matplotlib
import matplotlib.pyplot as plt
import re, sys


def parse_file (file_name):
    file = open("test.txt", "r")
    i = 0

    gbest = []
    var_value = []

    for line in file.readlines():

        if i == 0:
            plt.title(line)
            i = i + 1
            tmp = re.split(" ", line)
            plt.xlabel(tmp[len(tmp) - 1])
            continue

        tmp = re.split(" ", line)

        if len(tmp) != 2:
            print("Error: line has more then 2 values")
            break

        gbest.append(int(tmp[1]))
        var_value.append(int(tmp[0].strip()))

    print(gbest)
    print(var_value)

    plt.plot(var_value, gbest)
    plt.ylabel('Minimum global')
    plt.show()


