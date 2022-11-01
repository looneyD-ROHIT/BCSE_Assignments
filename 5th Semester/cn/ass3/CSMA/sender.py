import socket
import sys
import time
import random


def Main(senderno):
    print('Starting Sender', senderno)
    host = '127.0.0.1'
    port = 8080

    mySocket = socket.socket()
    mySocket.connect((host, port))
    prevtime = time.time()
    success = 0
    while True:
        print()
        data = input("Enter $ ")
        #prevtime = time.time()
        k = 0
        kmax = 5
        while True:
            print('ATTEMPT NUMBER:-', str(k))
            print('Checking the status of the channel')
            filein = open('status.txt', "r")
            status = int(filein.read())
            if status == 0:
                print("Channel is FREE!----------------")

                prob = random.uniform(0, 1)
                print('probability value is :', str(prob))
                print()
                if prob >= 0.5:
                    fileout = open('status.txt', "w")
                    fileout.write(str(1))
                    fileout.close()
                    waittime = random.randint(2, 8)
                    print('Channel has been allocated. It will take ' +
                          str(waittime)+' seconds to send!----------')

                    print('Sending to channel :', str(data))
                    time.sleep(waittime)
                    mySocket.send(data.encode())
                    success += 1
                    break
                else:

                    print('Waiting for time-slot 2 seconds...')
                    time.sleep(2)
                    filein = open('status.txt', "r")
                    status = int(filein.read())
                    print('After waiting for 2 second, the channel is', end=' ')
                    if status == 0:
                        print('IDLE')
                    else:
                        print('BUSY')
                    k += 1
                    if k > kmax:
                        print("Transmission aborted!!!!!!")
                        break

            elif status == 1:
                time.sleep(0.3)
                print("Channel is BUSY!")

            print()

        if not data:
            break
        if data == 'q':
            break

    print("------------------------------")
    curtime = time.time()
    totaltime = curtime - prevtime
    throughput = success/totaltime
    print("Throughput is  :", str(throughput))

    mySocket.close()


if __name__ == '__main__':
    if len(sys.argv) > 1:
        senderno = int(sys.argv[1])
    else:
        senderno = 1
    Main(senderno)
