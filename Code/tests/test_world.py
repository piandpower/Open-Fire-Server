from framework import Vector
from framework.world import World
from framework.world.actor.base import ActorType
from framework.world.actor.building import Castle
from framework.world.actor.unit import Worker
from framework.world.strongpoint import Strongpoint, Road

TEST_START_NODE_ID = 1
TEST_ACTOR_ID = 1


def test_castle_spawn_worker():
    castle = Castle(TEST_START_NODE_ID, TEST_ACTOR_ID)

    world = World(__generate_mock_strongpoints(), __generate_mock_roads(), [], [castle])
    world.update()

    assert world.get_node(castle.node_id).get_unit_by_type(ActorType.worker) is not None


def test_worker_move():
    worker_start_node_id = 1

    worker = Worker(worker_start_node_id, 1)

    world = World(__generate_mock_strongpoints(), __generate_mock_roads(), [worker], [])
    world.update()

    assert worker.node_id != worker_start_node_id


def test_worker_build_farm():
    worker_node_id = 1

    worker = Worker(worker_node_id, 1)

    world = World(__generate_mock_strongpoints(), __generate_mock_roads(), [worker], [])
    world.update()

    assert world.get_node(worker.node_id).get_building_by_type(ActorType.farm) is not None


def __generate_mock_strongpoints():
    strongpoints = [
        Strongpoint(1, Vector(0, 0), 1),
        Strongpoint(2, Vector(100, 0), 1),
        Strongpoint(3, Vector(0, 100), 1),
        Strongpoint(4, Vector(100, 100), 1)
    ]
    return strongpoints


def __generate_mock_roads():
    roads = [
        Road(1, 2),
        Road(1, 3),
        Road(1, 4),
        Road(2, 1),
        Road(2, 3),
        Road(2, 4),
        Road(3, 1),
        Road(3, 2),
        Road(3, 4),
        Road(4, 1),
        Road(4, 2),
        Road(4, 3)
    ]
    return roads
