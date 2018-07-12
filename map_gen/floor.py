from room import Room
from random import randint
from tools import hitbox_room


class Floor:

    def __init__(self):
        self.nbr_room = randint(8, 10)
        self.rooms = [Room() for _ in range(self.nbr_room)]
        self.pos_room = [[0, 0]]
        self.sizes = []
        self.get_sizes()

    def set_pos(self):
        for _ in range(self.nbr_room):
            print(_)
            if _ == 0:
                self.rooms[_].set_pos([0, 0])
            else:
                hit = True
                x = 0
                y = 0
                while hit:
                    maxx = self.rooms[_ - 1].width
                    maxy = self.rooms[_ - 1].height
                    x = randint(2, maxx) * (_ + 1)
                    y = randint(2, maxy) * (_ + 1)
                    hit = hitbox_room(self.rooms[_ - 1].pos, self.rooms[_ - 1].size, [x, y])
                    print(hit)
                self.rooms[_].set_pos([x, y])
            print(self.rooms[_].pos)
            print(self.rooms[_].size)
            print()

    def get_sizes(self):
        self.set_pos()
        for _ in range(self.nbr_room):
            self.sizes.append([self.rooms[_].pos[0] + self.rooms[_].width, self.rooms[_].pos[1] + self.rooms[_].height])
