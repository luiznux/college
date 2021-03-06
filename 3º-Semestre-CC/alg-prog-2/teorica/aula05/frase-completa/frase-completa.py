#funcão para verificar o tipo de frase digitada
#seu parametro é uma frase criada pelo usuario
def tipo_de_frase(frase):
    vetor_letras = "" #string 
    for letra in frase:
        if letra not in vetor_letras:#se a letra ñ estiver no vetor de letras 
            vetor_letras += letra #adiciona a letra no vetor alfabeto
    return len(vetor_letras) #retorna o tamanho do vetor
         
            
#funcão para abrir um arquivo e ler, com o nome de acordo com o 
#input do usuário,caso nao exista o arquivo, ele fica no laço
#e converte o arquivo para tudo minusculo
def abre_arquivo():
    while True:  
        print("Digite o nome do arquivo para ser carregado")
        print("Lembrando que o arquivo deve estar na mesma pasta em que este programa\n")
        nome_arquivo = input(">")
        if not os.path.exists(nome_arquivo):
            print("erro, o arquivo não existe")
        else:
            break
    arquivo = open(nome_arquivo, "r")
    dados = arquivo.read()
    arquivo.close()
    dados.lower()
    return dados
    

###################################################################################
#MAIN
#o programa vai ler o arquivo inteiro e nao por linhas!
import os

print("Este programa diz o tipo de sua frase(que é importada a partir de um arquivo)\n")

frase = abre_arquivo()

saida =  tipo_de_frase(frase)

if saida == 26:
    print(" Esta é uma frase COMPLETA!")
elif saida == 13:
    print(" Esta é uma frase QUASE COMPLETA")
else:
    print(" Esta frase MAL ELABORADA")
