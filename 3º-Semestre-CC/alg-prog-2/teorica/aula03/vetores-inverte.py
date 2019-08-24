
def inverte( V ):

    i = 0
    f = len(V)-1
    while i < f:
        aux = V[i]
        V[i] = V[f]
        V[f] = aux
        i+=1
        f-=1


# ---------MAIN
#cria o vetor

V = [ 9, 10, 8, 11, 5 ]

inverte( V )

print(V)








