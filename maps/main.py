from floor import Floor
from tools import *

fw = open("foo.txt", "w")

f1 = Floor()
highest = highest_size(f1.sizes)
write_blank_file(highest[0], highest[1], fw)

fw.close()

fr = open("foo.txt", "r")

fr.seek(0, 0)
temp = fr.read().splitlines()

tmp = []
for y in range(len(temp)):
    tmp.append([0] * len(temp[y]))

for _ in range(f1.nbr_room):
    for y in range(f1.rooms[_].height):
        for x in range(f1.rooms[_].width):
            tmp[y + f1.rooms[_].pos[1]][x + f1.rooms[_].pos[0]] += _ + 1

for y in range(len(tmp)):
    for x in range(len(tmp[y])):
        print(tmp[y][x], end='')
    print()

"""
for y in range(len(temp)):
    for x in range(len(temp[y])):
        print(temp[y][x], end='')
    print()
"""

fr.close()
