from flask import jsonify
from flask.views import MethodView
from ..database import session
from ..models import StrongPoint


class StrongPointView(MethodView):
    def get(self):

        strongpoints = []
        for strongpoint in session.query(StrongPoint).all():
            strongpoints.append({
                'strongpoint_id': strongpoint.strongpoint_id,
                'position_x': strongpoint.position_x,
                'position_y': strongpoint.position_y
            })

        response = jsonify({
            'strongpoints': strongpoints
        })
        return response
