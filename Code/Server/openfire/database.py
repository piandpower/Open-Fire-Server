from sqlalchemy import create_engine
from sqlalchemy.orm import scoped_session, sessionmaker
from .models import Base, StrongPoint, Edge
import random

engine = create_engine('sqlite:///:memory:', echo=True)
session_factory = sessionmaker(bind=engine)
session = scoped_session(session_factory)

Base.metadata.create_all(bind=engine)


def __add_test_data():
    nodecount = 100
    for i in range(nodecount):
        node = StrongPoint(i, 'node' + str(i), random.randrange(-5000, 5000), random.randrange(-5000, 5000))
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
