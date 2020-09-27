import socket

buffer_size = 1024

#Crio o  socket
s = socket.socket()

#Definindo porta e Ip do seridor
PORT = 31861
IP ='0.0.0.0'
s .bind((IP, PORT))

#abro 1 conexao
s.listen(1)

#crio e abro um arquivo para escrita
file = open("cliente.txt", "wb")

buffer = bytes()
#estabeleço conexao com o cliente
conn, addr = s.accept()

#recebo os dados do cliente
RecvData = conn.recv(1024)

while RecvData:

    #armazeno os dados recebidos em um buffer de memoria
    buffer = buffer+RecvData
    RecvData = conn.recv(buffer_size)

#escrevo em um arquivo os dados do buffer
file.write(buffer)

#fecho arquivo
file.close()

# Fecho a conexao com o cliente
conn.close()

