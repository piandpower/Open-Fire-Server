from world import World
from world.actor import ActorType
from world.actor.unit.worker import Worker
from world.static_actor import Node, Edge

from framework import Vector
from framework.world.actor.building.castle import Castle

TEST_START_NODE_ID = 1
TEST_ACTOR_ID = 1


def test_castle_spawn_worker():
    castle = Castle(TEST_START_NODE_ID, TEST_ACTOR_ID)

    world = World(__generate_mock_nodes(), __generate_mock_edges(), [], [castle])
    world.update()

    assert world.get_node(castle.node_id).get_unit_by_type(ActorType.worker) is not None


def test_worker_move():
    worker_start_node_id = 1

    worker = Worker(worker_start_node_id, 1)

    world = World(__generate_mock_nodes(), __generate_mock_edges(), [worker], [])
    world.update()

    assert worker.node_id != worker_start_node_id


def test_worker_build_farm():
    worker_node_id = 1

    worker = Worker(worker_node_id, 1)

    world = World(__generate_mock_nodes(), __generate_mock_edges(), [worker], [])
    world.update()

    assert world.get_node(worker.node_id).get_building_by_type(ActorType.farm) is not None


def __generate_mock_nodes():
    nodes = [
        Node(1, Vector(0, 0), 1),
        Node(2, Vector(100, 0), 1),
        Node(3, Vector(0, 100), 1),
        Node(4, Vector(100, 100), 1)
    ]
    return nodes


def __generate_mock_edges():
    edges = [
        Edge(1, 2),
        Edge(1, 3),
        Edge(1, 4),
        Edge(2, 1),
        Edge(2, 3),
        Edge(2, 4),
        Edge(3, 1),
        Edge(3, 2),
        Edge(3, 4),
        Edge(4, 1),
        Edge(4, 2),
        Edge(4, 3)
    ]
    return edges
