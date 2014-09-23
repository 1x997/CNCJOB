# /usr/bin/python
# -*- coding: utf-8 -*-
import socket
def check_tcp_status(ip, port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_address = (ip, port)
    print 'Connecting to %s:%s.' % server_address
    sock.connect(server_address)

    message = "some body come in  ! notice "
    print 'Sending "%s".' % message
    sock.sendall(message)

    print 'Closing socket.'
    sock.close()


if __name__ == "__main__":
    print check_tcp_status("192.168.1.102", 6000)