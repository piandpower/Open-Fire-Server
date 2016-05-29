from flask import jsonify

from model.strong_point import StrongPointModel


class StrongPoint:
    @staticmethod
    def read():
        strong_points = StrongPointModel.read()
        return jsonify(strong_points=strong_points)

    @staticmethod
    def read_by_user(user_id):
        return 'id: ' + str(user_id)
