from flask import Flask
from view.template import battlefield
from view.island import get

app = Flask(__name__, static_url_path='/static')

app.add_url_rule('/', view_func=battlefield, methods=['GET'])
app.add_url_rule('/islands', view_func=get, methods=['GET'])

if __name__ == '__main__':
    app.run()
