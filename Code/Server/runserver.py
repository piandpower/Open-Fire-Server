from openfire import create_app

app = create_app(test=True)
app.run(debug=True)
