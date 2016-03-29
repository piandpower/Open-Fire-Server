from ....database import session
from ....models import Building
from ....models import Unit


class BuildingAgent(object):
    buildings = None

    def __init__(self):
        self.buildings = session.query(Building).all()

    def update(self):
        for building in self.buildings:
            unit = Unit(building.strongpoint_id)
            session.add(unit)
