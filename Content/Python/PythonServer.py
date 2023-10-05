import json
from http.server import BaseHTTPRequestHandler, HTTPServer

host_name = 'localhost'
port = 8080


class MyServer(BaseHTTPRequestHandler):
    def _set_headers(self):
        self.send_response(200)
        self.send_header('content-type', 'application/json')
        self.end_headers()

    def do_GET(self):
        self._set_headers()
        with open('data.json', 'r') as data_file:
            data = json.load(data_file)
            #  print(data.decode())
            # print(json.dumps(data))
        print(data)
        self.wfile.write(json.dumps(data).encode())


if __name__ == "__main__":
    server_address = ('', port)
    web_server = HTTPServer(server_address, MyServer)
    try:
        print('server started at %s:%s', host_name, port)
        web_server.serve_forever()

    except KeyboardInterrupt:
        pass
