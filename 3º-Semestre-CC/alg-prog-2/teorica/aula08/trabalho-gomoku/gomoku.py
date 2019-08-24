#variaveis globais dos jogadores
global Jogador_1
global Jogador_2

Jogador_1 = 1
Jogador_2 = 2

#função para criar  uma matriz
def cria_matriz(linha,coluna):

    # cria (aloca) x linhas
    matriz = [0] * linha  
    for i in range(linha):
        # aloca uma nova linha com x colunas
        matriz[i]=[0] * coluna  
    return matriz

#-----------------------------------------------------------------------
#verifica a posição da jogada 
def step(tabuleiro,linha,coluna):
    
    if tabuleiro[linha][coluna] == 0:
        return True
    else:
        return False

#------------------------------------------------------------------------
# insere o valor do jogador(1 ou 2) na posição escolhida     
def insere(tabuleiro,linha,coluna,jogador):
    tabuleiro[linha][coluna] = jogador
    
#------------------------------------------------------------------------ 
#função para printar o tabuleiro_gomoku
def print_tabuleiro(tabuleiro,linha,coluna):
    for linha in range(0,len(tabuleiro)):
        print(" ")
        print(" ")
        for coluna in range(len(tabuleiro[0])):
            print("%2d"%tabuleiro[linha][coluna], "  ", end="")

#-------------------------------------------------------------------------
#funçao que verifica se possui 5 numeros iguais na mesma linha
def verifica_linha(tabuleiro,linha,coluna,jogador):
    #varrer a coluna toda
    contador = 0
    for i in range(len(tabuleiro[0])):
        if tabuleiro[linha][i] == jogador:
            contador +=1
        else:
            contador = 0
            
    return contador == 5
 
#-------------------------------------------------------------------------
#função que verifica se possui 5 nueros iguais na mesma coluna
def verifica_coluna(tabuleiro,linha,coluna,jogador):
    contador = 0
    for i in range(len(tabuleiro)):
        if tabuleiro[i][coluna] == jogador:
            contador += 1
        else:
            contador = 0

    return contador == 5
    
#-------------------------------------------------------------------------
#função que verica se possuem 5 numeros iguais na mesma diagonal
def verifica_diagonal(tabuleiro,linha,coluna,jogador):
    #varre para frente da diagonal
    contador = 0
    j = coluna
    for i in range(linha,len(tabuleiro)):
        if tabuleiro[i][j] == jogador:
            contador+= 1
        else:
            contador = 0
        j+=1
        
            
    for i in range(linha,0,-1):
        print(i,j)
        if tabuleiro[i][j] == jogador:

            contador+= 1
        else:
            contador = 0
        j-= 1
        
    return contador == 5
     
#-------------------------------------------------------------------------
#função que verifica o status do game(se alguem ganhou ou perdeu)
def status_game(tabuleiro,linha,coluna,jogador):
    x =  verifica_linha(tabuleiro,linha,coluna,jogador)
    y =  verifica_coluna(tabuleiro,linha,coluna,jogador)
    z =  verifica_diagonal(tabuleiro,linha,coluna,jogador)
    if x or y or z is True:

        return True
         
 #------------------------------------------------------------------------
#Função do  jogo     
def game():   

    #tabuleiro do gomoku
    tabuleiro_gomoku = cria_matriz(15,15)
    contador_do_jogador = 0
    jogador = 0
    
    while True:
        
        if contador_do_jogador%2 == 2:

            jogador = Jogador_2

        else:
            jogador = Jogador_1
        
        linha  = int(input("\nDigite a posicao linha que você deseja jogar: "))

        coluna = int(input("\nDigite a posicao coluna que você deseja jogar: "))

        verificacao = step(tabuleiro_gomoku,linha,coluna)

        if verificacao == False:
            print("\nA posição está ocupada, jogue em outro lugar\n")
            continue
        
        else:
            insere(tabuleiro_gomoku,linha,coluna,jogador)
            print_tabuleiro(tabuleiro_gomoku,15,15)

        if status_game(tabuleiro_gomoku,linha,coluna,jogador) == True:
            break

    print_tabuleiro(tabuleiro_gomoku)
    print("O jogador vencedor é o jogador:\n",jogador)

#___________________________________________________________________________________


game()
                
    
    
