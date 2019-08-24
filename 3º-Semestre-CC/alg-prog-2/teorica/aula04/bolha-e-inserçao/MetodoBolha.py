def Bolha(v):
    i=0
    while i < len(v)-1:
        #faca trocas sucessivas para borbulhar o primeiro do vetor
        #ate a ultima posicao do vetor
        j=0
        while j < len(v)-1-i:
            #troca duas posicoes do vetor
            if v[j] > v[j+1]:
                temp = v[j]
                v[j] = v[j+1]
                v[j+1]=temp
            j+=1
        i+=1
    
def main():
    #declarando um vetor

    vetor=[9,8,7,6,5,4,3,2] #tamanho fixo todos os elementos do mesmo tipo
    
    # chama busca linear
    Bolha(vetor)
    print(vetor)
   
    
#--------------------------
#chamada do main
main()
