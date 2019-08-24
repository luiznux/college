'''
Funcao busca um elemento no vetor passado por parametro
se o elemento estiver presente a funcao retorna True
caso contrario False
'''
def esta( vetor, x ):
    i = 0
    while i < len(vetor):
        if x == vetor[i]:
            #achou
            return True
        i+=1
    # se andei todo o vetor e não achei retorna False
    return False

#--- MAIN

# aloca um vetor com 4 posicoes
vetor = [0]*4

# insere elementos no vetor
vetor[0] = 10
vetor[1] = 20
vetor[2] = 30
vetor[3] = 40

print("resposta funcao",esta(vetor, 50))
print("resposta operador in",50 in vetor) #usando lista, mas não  pode


    
