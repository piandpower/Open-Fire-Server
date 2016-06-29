from flask import render_template
from flask.views import MethodView


class BattleField(MethodView):
    @staticmethod
    def get():
        return render_template('battlefield.html')

