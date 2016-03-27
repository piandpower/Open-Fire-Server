import random
import math


class Vector(object):
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        if type(other) == type(self):
            return Vector(self.x + other.x, self.y + other.y)

    def __mul__(self, other):
        if type(other) == float or type(other) == int:
            return Vector(self.x * other, self.y * other)

    def dist_squared(self, other):
        dx = other.x - self.x
        dy = other.y - self.y

        return (dx * dx) + (dy * dy)


def get_random_vector():
    x = 0
    y = 1

    angle = random.uniform(-math.pi, math.pi)
    cos_theta = math.cos(angle)
    sin_theta = math.sin(angle)

    nx = x * cos_theta - y * sin_theta
    ny = x * sin_theta + y * cos_theta

    return Vector(nx, ny)


def zero_vector():
    return Vector(0, 0)
