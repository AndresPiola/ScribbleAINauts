import requests
import json

# apikey
token = '3478733645d9495e9ec1b0700f10cd0f'
headers = {'content-type': 'application/json; charset=utf8', 'X-Auth-Token': '3478733645d9495e9ec1b0700f10cd0f'}
model_keyword = 'chair'
result = requests.get("https://api.poly.pizza/v1/search/" + model_keyword, headers=headers)
results_array = result.json()
with open('data.json', 'w') as f:
    json.dump(results_array, f)
results_array = results_array['results']

print(results_array)
# for result in results_array:
#    print(result['Download'])
print(results_array)
# print(result.json())
