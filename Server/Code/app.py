from flask import Flask
from view import StrongPoint, BattleField, Island

app = Flask(__name__, static_url_path='/static')

app.add_url_rule('/', view_func=BattleField.as_view('BattleField'))
app.add_url_rule('/islands', view_func=Island.as_view('Island'))
app.add_url_rule('/strong-points', view_func=StrongPoint.read, methods=['GET'])
app.add_url_rule('/strong-points/user=<int:user_id>', view_func=StrongPoint.read_by_user, methods=['GET'])

if __name__ == '__main__':
    app.run()
