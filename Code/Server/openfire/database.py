from sqlalchemy import create_engine
from sqlalchemy.orm import scoped_session, sessionmaker
from .models import Base, Node
import random


def create_session():
    engine = create_engine('sqlite:///:memory:', echo=True)
    session_factory = sessionmaker(bind=engine)
    session = scoped_session(session_factory)

    Base.metadata.create_all(bind=engine)
    for i in range(5):
        node = Node(name='node'+str(i), position_x=random.randrange(1, 11), position_y=random.randrange(1,11))
        session.add(node)
    session.commit()

    return session
