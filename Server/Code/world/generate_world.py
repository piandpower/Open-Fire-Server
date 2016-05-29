from world import World
from model import StrongPointModel

world = World()
for node in world.nodes:
    StrongPointModel.create(node.x, node.y)

