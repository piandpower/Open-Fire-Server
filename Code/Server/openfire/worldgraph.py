import random


class StrongPoint:
    def __init__(self, strongpoint_id, position_x, position_y):
        self.strongpoint_id = strongpoint_id
        self.position_x = position_x
        self.position_y = position_y


def generate_random_strongpoints():
    strongpoints = []
    for i in range(100):
        strongpoints.append(StrongPoint(i, random.randrange(-5000, 5000), random.randrange(-5000, 5000)))

    return strongpoints
