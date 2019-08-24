'''
Funcao busca um elemento no vetor passado por parametro
se o elemento estiver presente a funcao retorna o indice do elemento
caso nao encontre a funcao retorna -1, caso tenhamos elementos repetidos
a funcao retorna o indice do 1o 
'''
#declaracao de variavel global
cont = 0
def buscaLinear( v, x):
    global cont
    cont = 0
    k=0
    while k < len(v):
        cont+=1
        if v[k] == x:
            return k
        k+=1

    return -1;
'''
implementacao da busca binaria
A função recebe um número x e um vetor em ordem crescente v[0..n-1]com n elementos.
A função devolve um índice m tal que v[m] == x, ou seja achou x em v[], ou devolve -1
se tal m não existe.
'''
def buscaBinaria( v, x):
    global cont
    i = 0
    f = len(v)-1
    cont = 0
    while i<=f:
        cont+=1
        m = (i+f)//2
        if x == v[m]:
            return m
        if x > v[m]:
            i = m + 1
        else:
            f = m - 1
    return -1


#--- MAIN
N = 1024
# aloca um vetor com 4 posicoes
vetor = [0]*N

# insere elementos no vetor
for i in range(1,N+1):
    vetor[i-1]=i
print(vetor)
print("resposta funcao BuscaLinear",buscaLinear(vetor, N+1))
print("quantidade de repeticoes para o pior caso(pior configuracao de entrada):",cont)

print("resposta funcao BuscaBinaria",buscaBinaria(vetor, N+1))
print("quantidade de repeticoes para o pior caso(pior configuracao de entrada):",cont)




    
