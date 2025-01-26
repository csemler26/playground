from flask import Flask, jsonify, request

app = Flask(__name__)

# In-memory "database"
data = {"message": "Hello, world!"}

# Route for GET request
@app.route('/api/message', methods=['GET'])
def get_message():
  return jsonify(data), 200

# Route for POST request
@app.route('/api/message', methods=['POST'])
def set_message():
  content = request.json
  data['message'] = content.get('message', data['message'])
  return jsonify({"status": "success", "message": data['message']}), 200

if __name__ == '__main__':
  app.run(debug=True)
