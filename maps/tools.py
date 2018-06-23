def highest_size(pos):
    highest = [0, 0]
    for _ in range(len(pos)):
        if pos[_][0] >= highest[0]:
            highest[0] = pos[_][0]
        if pos[_][1] >= highest[1]:
            highest[1] = pos[_][1]
    return highest


def write_blank_file(width, height, fw):
    for y in range(height):
        for x in range(width):
            fw.write('a')
        fw.write('\n')


def hitbox_room(pos_room, size_room, pos):
    xo = pos_room[0]
    yo = pos_room[1]
    xm = pos_room[0] + size_room[0]
    ym = pos_room[1] + size_room[1]
    if (pos[0] >= xo) and (pos[0] <= xm):
        if (pos[1] >= yo) and (pos[1] <= ym):
            return True
    return False
