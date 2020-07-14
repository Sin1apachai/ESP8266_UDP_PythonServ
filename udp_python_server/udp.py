import socket

HOST = '0.0.0.0'
PORT = 4000

BUFFER_SIZE = 1024

server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server.bind((HOST, PORT))

print("Start Server")
while True:
    data = server.recvfrom(BUFFER_SIZE)
    if data:
        print('Client to Server: ', data)
        server.sendto(data[0].upper(), data[1])

server.close()
