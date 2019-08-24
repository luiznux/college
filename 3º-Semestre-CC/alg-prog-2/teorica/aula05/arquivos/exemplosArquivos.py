# copia um arquivo para um outro, caso o arquivo destino nao exista 
# o mesmo eh criado

f1 = open("entrada.txt", "r")
f2 = open("saida.txt", "w")

while True:
    texto = f1.readline()
    if texto == "": # se string vazia finaliza a leitura
        break
    f2.write(texto)
    #print(texto, end="")

f1.close()
f2.close()

