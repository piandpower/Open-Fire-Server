def create_views(app):
    @app.route('/')
    def hello_world():
        return 'Hello World!'
