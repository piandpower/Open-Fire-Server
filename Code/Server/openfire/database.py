from sqlalchemy import create_engine
from sqlalchemy.orm import scoped_session, sessionmaker
from .models import Base, StrongPoint, Edge
from .worldgraph import generate_random_strongpoint_locations

engine = create_engine('sqlite:///:memory:', echo=True)
session_factory = sessionmaker(bind=engine)
session = scoped_session(session_factory)

Base.metadata.create_all(bind=engine)


def __generate_edges(strongpoints):
    edges = []
    for strongpoint_start in strongpoints:
        for strongpoint_end in strongpoints:
            if strongpoint_start != strongpoint_end:
                dx = strongpoint_start.position_x - strongpoint_end.position_x
                dy = strongpoint_start.position_y - strongpoint_end.position_y
                dist_squared = (dx * dx) + (dy * dy)
                if dist_squared < (700 * 700):
                    edges.append(Edge(strongpoint_start.strongpoint_id, strongpoint_end.strongpoint_id))

    return edges


def __add_test_data():
    strongpoint_locations = generate_random_strongpoint_locations()
    strongpoints = []
    for location in strongpoint_locations:
        strongpoints.append(StrongPoint(location.x, location.y))

    session.add_all(strongpoints)
    session.commit()

    strongpoints = session.query(StrongPoint).all()
    session.add_all(__generate_edges(strongpoints))
    session.commit()

__add_test_data()
