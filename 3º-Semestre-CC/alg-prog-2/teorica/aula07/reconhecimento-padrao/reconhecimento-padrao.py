#----------------Funções para criar a matriz a partir do arquivo-------------------------------------------------#

#cria uma matriz com zeros e tamanho definido pelos parametros
def cria_matriz(linha,coluna):
    matriz = [None] * linha   # cria (aloca) x linhas
    for i in range(linha):
        matriz[i]=[0]*coluna  # aloca uma nova linha com x colunas
    return matriz

#verifica o tamanho da matriz lendo a primeira linha do arquivo
def tam_matriz_arquivo(arquivo):
    with open(arquivo) as filename:
        lista = filename.readline()#remove o \n e pega o tamanho da matriz
        matriztemp = []
        linha = int(lista[0])
        coluna = int(lista[2])
        if linha < 3 or coluna < 3:
            print(" Erro! a matriz informada tem que ser maior que 3 linhas e 3 colunas ")
            return
    return linha, coluna

#cria a matriz com os elementos do arquivo a partir da segunda linha 
def cria_matriz_arquivo(arquivo,linha,coluna):
    matriz_criada = cria_matriz(linha,coluna)
    with open(arquivo) as file:
        file.readline()
        cont_linha = 0
        for line in file:
            cont_col = 0
            for numero in line.split():
                matriz_criada[cont_linha][cont_col] = float(numero)
                cont_col += 1
            cont_linha += 1
                
    return matriz_criada

#-----------------------------------------Funções para calcular a gravidade---------------------------------------------------------#

#soma todos os elementos de todas as linhas da matriz dada e retorna um vetor com o resultado de todas as somas
def somaLinha(matriz):
    vetor_das_somas = []
    soma = 0 
    for linha in range(len(matriz)):
        for coluna in range(len(matriz[0])):
            soma += matriz[linha][coluna] 
        vetor_das_somas.append(soma)
        soma = 0
    return vetor_das_somas


#soma todos os elementos de todas as colunas da matriz dada e retorna um vetor com o resultado de todas as somas 
def somaColuna(matriz):
    vetor_das_somas = []
    soma = 0
    for linha in range(len(matriz[0])):
        for coluna in range(len(matriz)):
            soma += matriz[coluna][linha]
        vetor_das_somas.append(soma)
        soma = 0
    return vetor_das_somas




def centro_gravidade(vetor):

    for i in range(1,len(vetor)-2):
        x = 0 
        contU = 0
        contD = 0
        menor = -1
        pos = 0 

        while x < i:
            contU += vetor[x]
            x +=1
        if x == i:
            x += 1

        while x < len(vetor):
            contD += vetor[x]
            x += 1

        if menor == -1:
            menor = contU - contD
            pos = i
            
        if abs(contU - contD) < menor:
            menor = abs(contU -contD)
            pos = i #posição do centro
        
        if x < 0:
            x = x*-1

        else:
            if i == 1:
                menor = x

            if x < menor:
                menor = x
                pos = i


    return(pos)


#----------------------------MAIN------------------------------------------#
arquivo = input("Digite o nome do arquivo para ser lido:\n ---> ")
linha,coluna = tam_matriz_arquivo(arquivo)
print(linha,coluna)
matriz_criada = cria_matriz_arquivo(arquivo,linha,coluna)


'''matriz_criada = [[5,5,5,5,5],[2,2,2,1,3],[5,5,5,5,5],[5,5,5,5,5],[5,5,5,5,5]] '''
for i in range(0,len(matriz_criada)):
        print(matriz_criada[i],"\n") 

Soma_das_linhas = somaLinha(matriz_criada)
print("a soma das linhas é --",Soma_das_linhas, "\n")

Soma_das_colunas = somaColuna(matriz_criada)
print("a soma das colunas é --",Soma_das_colunas,"\n")

centro_linha = centro_gravidade(Soma_das_linhas)
print("centro linha é", centro_linha, "\n")

centro_coluna = centro_gravidade(Soma_das_colunas)
print("centro coluna é", centro_coluna,"\n")

print("O centro de gravidade da matriz de seu arquivo é :\n --->" "linha[",centro_linha,"]","coluna[",centro_coluna,"]")
