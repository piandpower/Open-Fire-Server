from flask import Flask
from view import BattleField, Island

app = Flask(__name__, static_url_path='/static')

app.add_url_rule('/', view_func=BattleField.as_view('BattleField'))
app.add_url_rule('/islands', view_func=Island.as_view('Island'))

if __name__ == '__main__':
    app.run()
