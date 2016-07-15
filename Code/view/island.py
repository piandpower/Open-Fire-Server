from flask import jsonify
from flask.views import MethodView
from framework.database.model.static_actor import Road, Strongpoint


class Island(MethodView):
    @staticmethod
    def get():
        nodes = []
        for strongpoint in Strongpoint.read():
            nodes.append({
                'id': strongpoint.rid,
                'x': strongpoint.location.x,
                'y': strongpoint.location.y,
                'level': strongpoint.level
            })

        edges = []
        for road in Road.read():
            edges.append({
                'start_node_id': road.start_id,
                'end_node_id': road.end_id
            })

        return jsonify(nodes=nodes, edges=edges)
