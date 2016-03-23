from sqlalchemy import create_engine
from sqlalchemy.orm import scoped_session, sessionmaker
from .models import Base, Node, Edge
import random

engine = create_engine('sqlite:///:memory:', echo=True)
session_factory = sessionmaker(bind=engine)
session = scoped_session(session_factory)

Base.metadata.create_all(bind=engine)


def add_test_data():
    nodecount = 5
    for i in range(nodecount):
        node = Node(i, 'node'+str(i), random.randrange(1, 11), random.randrange(1,11))
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

add_test_data()
