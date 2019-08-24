def insercao(v):
    for k in range(1,len(v)):
        x  = v[k]
        i = k-1
        while i>=0 and x<v[i]:
            v[i+1]=v[i]
            i-=1

        v[i+1]=x
    
def main():
    #declarando um vetor
    #vetor=[10,9,8,7,6,5,4,3,2,1] #tamanho fixo todos os elementos do mesmo tipo
    vetor=[1,-2,3,-4,5,-6,6,6,-7,7,7,8]
    print(vetor)
    # chama busca linear
    insercao(vetor)
    print(vetor)
   
    
#--------------------------
#chamada do main
main()
