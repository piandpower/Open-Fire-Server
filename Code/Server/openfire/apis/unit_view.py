from flask import jsonify
from flask.views import MethodView
from ..database import session
from ..models import Unit


class UnitView(MethodView):
    def get(self):

        units = []
        for unit in session.query(Unit).all():
            units.append({
                'unit_id': unit.unit_id,
                'strongpoint_id': unit.strongpoint_id
            })

        response = jsonify({
            'units': units
        })
        return response
