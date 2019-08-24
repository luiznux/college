#abre o arquivo entrada.txt para leitura
arquivo = open("entrada.txt",'r')


# le as linhas do arquivo
linha1 = arquivo.readline();
linha2 = arquivo.readline();
#cria o vetor
vetor=[0]*int(linha1)

vetorString = linha2.split(" ")
i = 0
while i < len(vetor):
    vetor[i]=int(vetorString[i])
    i+=1

print(vetor)

#fecha o arquivo
arquivo.close()
