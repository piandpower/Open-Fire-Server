from flask import jsonify
from flask.views import MethodView
from framework.database.model import Road, Strongpoint


class Island(MethodView):
    @staticmethod
    def get():
        strongpoints = []
        for strongpoint in Strongpoint.read():
            strongpoints.append({
                'id': strongpoint.rid,
                'x': strongpoint.x,
                'y': strongpoint.y,
                'level': strongpoint.level,
                'request': strongpoint.request
            })

        roads = []
        for road in Road.read():
            roads.append({
                'start_node_id': road.start_id,
                'end_node_id': road.end_id
            })

        return jsonify(strongpoints=strongpoints, roads=roads)
