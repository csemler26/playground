import requests

# The URL of the API server
url = "http://127.0.0.1:5000/api/message"

# Get the current message from the server
response = requests.get(url)
if response.status_code == 200:
  print("GET Response:", response.json())

# Send a POST request to update the message
new_message = {"message": "Hello from the client!"}
response = requests.post(url, json=new_message)
if response.status_code == 200:
  print("POST Response:", response.json())

# Get the updated message from the server
response = requests.get(url)
if response.status_code == 200:
  print("Updated GET Response:", response.json())
