from flask import jsonify
from flask.views import MethodView
from ..database import session
from ..models import StrongPoint, Edge


class StrongPointView(MethodView):
    def get(self):

        strongpoints = []
        for strongpoint in session.query(StrongPoint).all():
            strongpoints.append({
                'strongpoint_id': strongpoint.strongpoint_id,
                'position_x': strongpoint.position_x,
                'position_y': strongpoint.position_y
            })

        edges = []
        for edge in session.query(Edge).all():
            edges.append({
                'start_strongpoint_id': edge.start_strongpoint_id,
                'end_strongpoint_id': edge.end_strongpoint_id
            })

        response = jsonify({
            'strongpoints': strongpoints,
            'edges': edges
        })
        return response
