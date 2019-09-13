import math

def calcula_polinomio(valor,vetor):

    resultado = 0

    for i in range(0,len(vetor)-1,2):

        resultado += (valor**vetor[i+1]) * vetor[i]

    resultado += vetor[len(vetor)-1]

    return resultado


def sinal(numero):

    if numero >= 0:
        return True

    else:
        return False


'''def bissesao(x, y, equacao):

    if sinal(x) == sinal(y):
        print("não é possivel calcular")
        return false

    else:
        for i in range()
'''




tolerancia = float(0.01)

intervalo_a = 1

intervalo_b = 2

equacao = [1,3,4,2,-10]

x =calcula_polinomio(intervalo_a,equacao)

y =calcula_polinomio(intervalo_b,equacao)

print(x,y)


