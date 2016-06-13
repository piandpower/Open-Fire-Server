from model import StrongPointModel
from world import WorldGenerator

wg = WorldGenerator()
wg.generate()

for node in wg.nodes:
    StrongPointModel.create(node.x, node.y)
