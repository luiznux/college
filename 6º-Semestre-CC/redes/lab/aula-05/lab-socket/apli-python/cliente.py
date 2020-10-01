import socket

# Crio um socket
s = socket.socket()

# Defindo porta e Ip do servidor
PORT = 31861
IP = "0.0.0.0"
# tamanho do buffer
buffer_size = 1024

#faço a conexao com o servidor
s.connect((IP, PORT))

#input para o cliente inserir o arquivo
arquivo_cliente = input("Digite o nome do arquivo desejado: \n OBS: deixe o arquivo selecionado no mesmo diretorio ou coloque o full path  \n -> ")

#abro o arquivo para leitura em bytes do arquivo
file = open(arquivo_cliente, "rb") #read binary

#leio o arquivo em memoria e envio 1024 bytes
SendData = file.read(buffer_size)

while SendData:

    #envio os  chunks do arquivo
    s.send(SendData)
    SendData = file.read(buffer_size)

#fecho o arquivo
file.close()

#encerro a conexao
s.close()
