from typing import List
from .static_actor import Node, Edge
from .actor import Unit


class World:
    def __init__(self, nodes: List[Node], edges: List[Edge], units: List[Unit]):
        self.__add_nodes(nodes)
        self.__add_edges(edges)
        self.__add_units(units)

    def update_move(self):
        for unit in self.units:
            dest_node_id = unit.get_update_move_dest_node_id(self.nodes[unit.node_id])
            self.__move_actor(unit.node_id, dest_node_id, unit.actor_id)

    def update_act(self):
        for node in self.nodes.values():
            node.update()

    def __add_nodes(self, nodes: List[Node]):
        self.nodes = dict()
        for node in nodes:
            self.nodes[node.node_id] = node

    def __add_edges(self, edges: List[Edge]):
        for node in self.nodes.values():
            for edge in edges:
                if node.node_id == edge.start_node_id:
                    node.add_nearby_node(self.nodes[edge.end_node_id])

    def __add_units(self, units: List[Unit]):
        self.units = units

        for node in self.nodes.values():
            for unit in units:
                if node.node_id == unit.node_id:
                    node.add_unit(unit)

    def __move_actor(self, current_node_id: int, dest_node_id: int, actor_id: int):
        actor = self.nodes[current_node_id].pop_unit(actor_id)
        self.nodes[dest_node_id].add_unit(actor)
        actor.node_id = dest_node_id
