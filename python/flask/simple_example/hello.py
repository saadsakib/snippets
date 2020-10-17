from flask import Flask, request

# How to run
#
# python3 hello.py
#
# Optionally, 
# export FLASK_DEBUG=1

app = Flask(__name__)

@app.route('/')
def index():
    return '<h1>Hello!</h1>'

@app.route('/<name>')
def handle_name(name):
    return f'<h1>Hello {name}!</h1>'

@app.route('/sample', methods=['POST']) 
def post_data():
    if request.json:
        return f"POST method called with data\n" + \
            f"{request.json}\n"
    else:
        return "POST method called without data\n"

if __name__ == '__main__':
	app.run(host='0.0.0.0', port=7000)