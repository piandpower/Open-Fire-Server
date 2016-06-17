from flask import render_template


class BattleField:
    @staticmethod
    def index():
        return render_template('battlefield.html')
