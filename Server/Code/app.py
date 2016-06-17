from flask import Flask
from view import StrongPoint, BattleField

app = Flask(__name__, static_url_path='/static')


@app.route('/')
def index():
    return BattleField.index()

app.add_url_rule('/strong-points', view_func=StrongPoint.read, methods=['GET'])
app.add_url_rule('/strong-points/user=<int:user_id>', view_func=StrongPoint.read_by_user, methods=['GET'])

if __name__ == '__main__':
    app.run()
