from typing import Iterable

NODE_SPACING = 10.0


class Node:
    def __init__(self, node_id, x, y):
        self.node_id = node_id
        self.x = x
        self.y = y


class Edge:
    def __init__(self, start_node_id, end_node_id):
        self.start_node_id = start_node_id
        self.end_node_id = end_node_id


class World:
    nodes = []
    edges = []

    def __init__(self):
        self._generate_world()

    def _generate_world(self):
        self.nodes = World._generate_nodes()
        self.edges = World._generate_edges(self.nodes)

    @staticmethod
    def _generate_nodes():
        nodes = []
        node_id = 1
        for x in range(10):
            for y in range(10):
                nodes.append(Node(node_id, x * NODE_SPACING, y * NODE_SPACING))
                node_id += 1

        return nodes

    @staticmethod
    def _generate_edges(nodes: Iterable[Node]):
        edges = []
        for start_node in nodes:
            for end_node in nodes:
                if start_node.node_id != end_node.node_id and World._has_edge(start_node, end_node):
                    edges.append(Edge(start_node.node_id, end_node.node_id))

        return edges

    @staticmethod
    def _has_edge(start_node: Node, end_node: Node):
        node_spacing = NODE_SPACING * 1.1
        dist_x = start_node.x - end_node.x
        dist_y = start_node.y - end_node.y
        if node_spacing * node_spacing > ((dist_x * dist_x) + (dist_y * dist_y)):
            return False

        return True
