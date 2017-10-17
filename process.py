import csv
import matplotlib.pyplot as plt
import sys

fname = "out/" + sys.argv[1] + ".csv"
file = open(fname, "r")

try:
     dict = {}
     reader = csv.reader(file)
     for row in reader:
        first = row.pop(0)
        dict[first] = row

     for key in dict:
        x1 = int(int(key) % 5)
        y1 = int(int(key) / 5)
        val = dict[key]
        for p in val:
            x2 = int(int(p) % 5)
            y2 = int(int(p) / 5)
            plt.plot([x1, x2], [y1, y2], marker = "o")
     plt.suptitle(fname)
     plt.grid()
     plt.show()

finally:
      file.close()
