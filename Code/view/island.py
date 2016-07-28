from flask import jsonify
from framework.database.core.session import Session
from framework.database.model import Road, Strongpoint


def get():
    session = Session()
    strongpoints = []
    for strongpoint in session.query(Strongpoint).all():
        strongpoints.append({
            'id': strongpoint.id,
            'x': strongpoint.location_x,
            'y': strongpoint.location_y,
            'level': strongpoint.level
        })

    roads = []
    for road in session.query(Road).all():
        roads.append({
            'start_strongpoint_id': road.start_strongpoint_id,
            'end_strongpoint_id': road.end_strongpoint_id
        })

    return jsonify(strongpoints=strongpoints, roads=roads)
