from flask import request, jsonify
from flask.views import MethodView
from ..database import session
from ..models import Building


class BuildingView(MethodView):
    def get(self):

        buildings = []
        for building in session.query(Building).all():
            buildings.append({
                'building_id': building.building_id,
                'strongpoint_id': building.strongpoint_id
            })

        response = jsonify({
            'buildings': buildings
        })
        return response

    def post(self):
        strongpoint_id = request.json['strongpoint_id']
        building = Building(strongpoint_id)
        session.add(building)

        response = jsonify({})
        response.status_code = 201
        return response
