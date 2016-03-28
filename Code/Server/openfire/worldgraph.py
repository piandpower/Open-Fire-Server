import random
from .framework.vector import get_random_vector, zero_vector


def generate_random_strongpoint_locations():
    locations = [zero_vector()]
    added_locations = [zero_vector()]
    for i in range(15):
        random_locations = __get_random_stretch_locations(added_locations, 400, 700, 3)
        added_locations = __add_suitable_locations(random_locations, locations, 400)

    strongpoints = []
    for location in locations:
        strongpoints.append(location)

    return strongpoints


def __get_random_stretch_locations(start_locations, min_distance, max_distance, count):
    random_locations = []
    for start_location in start_locations:
        for i in range(count):
            distance = random.randrange(min_distance, max_distance)
            random_location = start_location + (get_random_vector() * distance)
            random_locations.append(random_location)

    return random_locations


def __add_suitable_locations(source_locations, target_locations, distance):
    added_locations = []

    for source_location in source_locations:
        if not __is_exist_on_range(source_location, target_locations, distance):
            target_locations.append(source_location)
            added_locations.append(source_location)

    return added_locations


def __is_exist_on_range(source_location, target_locations, distance):
    dist_squared = distance * distance

    for location in target_locations:
        if source_location.dist_squared(location) < dist_squared:
            return True

    return False
