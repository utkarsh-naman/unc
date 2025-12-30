import http.server
import socketserver
import os

PORT = 8000

class WasmHandler(http.server.SimpleHTTPRequestHandler):
    def end_headers(self):
        # Enable Cross-Origin Resource Sharing (CORS)
        self.send_header("Access-Control-Allow-Origin", "*")
        super().end_headers()

    def do_GET(self):
        # Force correct MIME types for WASM files
        if self.path.endswith('.wasm'):
            self.send_header("Content-Type", "application/wasm")
        super().do_GET()

# Ensure we are serving from the directory where the script is located
os.chdir(os.path.dirname(os.path.abspath(__file__)))

print(f"Serving at http://localhost:{PORT}")
print("Press Ctrl+C to stop.")

with socketserver.TCPServer(("", PORT), WasmHandler) as httpd:
    httpd.serve_forever()
