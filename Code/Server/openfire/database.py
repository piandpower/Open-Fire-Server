from sqlalchemy import create_engine
from sqlalchemy.orm import scoped_session, sessionmaker
from .models import Base, StrongPoint, Edge
from .worldgraph import generate_random_strongpoints

engine = create_engine('sqlite:///:memory:', echo=True)
session_factory = sessionmaker(bind=engine)
session = scoped_session(session_factory)

Base.metadata.create_all(bind=engine)


def __add_test_data():
    strongpoints = generate_random_strongpoints()

    for strongpoint in strongpoints:
        node = StrongPoint(strongpoint.strongpoint_id, strongpoint.position_x, strongpoint.position_y)
        session.add(node)

    session.add_all(
        [
            Edge(0, 1),
            Edge(0, 3),
            Edge(0, 4),
            Edge(1, 2),
            Edge(2, 3),
            Edge(3, 4)
        ])

    session.commit()

__add_test_data()
