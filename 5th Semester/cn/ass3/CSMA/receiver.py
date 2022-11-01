import socket
import sys
import time
import random


def Main(recno):
    print('Starting Receiver ', recno)
    host = '127.0.0.2'
    port = 9090

    mySocket = socket.socket()
    mySocket.connect((host, port))

    while True:
        print()
        data = mySocket.recv(1024).decode()
        if not data:
            break
        if data == 'q':
            break

        print('Received from channel :', str(data))

    mySocket.close()


if __name__ == '__main__':
    if len(sys.argv) > 1:
        recno = int(sys.argv[1])
    else:
        recno = 1
    Main(recno)
