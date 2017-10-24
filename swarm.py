import matplotlib
import matplotlib.pyplot as plt
import re, sys


def parse_file (file_name):
    file = open(file_name, "r")
    i = 0

    title =""

    gbest = []
    var_value = []

    for line in file.readlines():

        if i == 0:
            plt.title(line)
            title = line
            i = i + 1
            tmp = re.split(" ", line)
            plt.xlabel(tmp[len(tmp) - 1])
            continue

        tmp = re.split(" ", line)

        if len(tmp) != 2:
            print("Error: line has more then 2 values")
            break

        gbest.append(float(tmp[1].strip()))
        var_value.append(float(tmp[0]))

#    print(gbest)
#    print(var_value)

    plt.plot(var_value, gbest)
    plt.ylabel('Minimum global')
#    plt.show()

    title += ".png"

    plt.savefig(title);


for i in range (len(sys.argv)):
    if i == 0:
        continue
    parse_file(sys.argv[i])
