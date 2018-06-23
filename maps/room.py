from random import randint


class Room:

    def __init__(self):
        self.width = randint(12, 26)
        self.height = randint(8, 22)
        self.map = [['.'] * self.width for _ in range(self.height)]
        self.create_map()
        self.pos = []
        self.size = [self.width, self.height]

    def set_pos(self, pos):
        self.pos = pos

    def create_map(self):
        self.map[0] = ['#'] * self.width
        self.map[self.height - 1] = ['#'] * self.width
        for _ in range(self.height):
            self.map[_][0] = '#'
            self.map[_][self.width - 1] = '#'

    def print_map(self):
        for y in range(self.height):
            for x in range(self.width):
                print(self.map[y][x], end='')
            print()
