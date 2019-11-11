import math

##Bruno Severo Camilo TIA: 41781619

##Luiz tagliaferro TIA: 31861806

def metodonewton(f,flin,x0,e,iteracoes):

  if abs(f(x0))<= e:
    return x0

  print("k\t x0\t\t\t\t f(pn-1) \t\t f'(pn-1) \t\t f(pn-1)/f'(pn-1) \t Pn")
  k=1
  
  while k<=iteracoes:
    print ("%d \t%e \t%e \t%e \t%e \t%e" % (k,x0,f(x0),flin(x0),f(x0)/flin(x0),x0-(f(x0)/flin(x0))))
    x1 = x0 - f(x0)/flin(x0)
    if abs(f(x1))<= e:
      print ("%d \t%e \t%e \t%e \t%e \t%e" % (k+1,x1,f(x1),flin(x1),f(x1)/flin(x1),x1-(f(x1)/flin(x1))))
      return x1
    x0=x1
    k=k+1
  print("Maximo de interacoes atingidas")
  return x1

if __name__ == "__main__":
  def f(x):
    return math.cos(x)-x
  def flin(x):
    return -math.sin(x)-1
  def fa(x):
    return (math.e**x)+(2**-x)+(2*math.cos(x)-6)
  def falin(x):
    return -2*math.sin(x)+(math.e**x)-math.lgamma(2)/2**x
  def fb(x):
    return math.lgamma(x-1)+math.cos(x-1)
  def fblin(x):
    return (math.lgamma(-math.sin(x-1)))
  def fc(x):
    return 2*x*(math.cos(2*x))-((x-2)**2)
  def fclin(x):
    return -2*(2*x*math.sin(2*x)-math.cos(2*x)+x-2)
  def fd(x):
    return (x-2)**2 - math.lgamma(x)
  def fdlin(x):
    return 2*(x-2)-1/x
  def fe(x):
    return (math.e**x) - (3*x**2)
  def felin(x):
    return math.e**2-6*x
  def ff(x):
    return math.sin(x)-math.e**-x
  def fflin(x):
    return math.cos(x)+math.e**-x 

raiz = metodonewton(f,flin,0.5,0.0001,10)

print("for 1 <=x<=2")
raiza = metodonewton(fa,falin,1,0.00001,10)

print("for 1.3 <=x<=2")
raizb = metodonewton(fb,fblin,1.5,0.00001,10)

print("for 2 <=x<=3")
raizc = metodonewton(fc,fclin,2,0.00001,10)

print("for 3 <=x<=4")
raizc1 = metodonewton(fc,fclin,4,0.00001,10)

print("for 1 <=x<=2")
raizd = metodonewton(fd,fdlin,1,0.00001,10)

print("for e <=x<=4")
raizd1 = metodonewton(fd,fdlin,3,0.00001,10)

print("for 0 <=x<=1")
#raize = metodonewton(fe,felin,1,0.00001,10)

print("for 3 <=x<=5")
raize1 = metodonewton(fe,felin,3,0.00001,10)

print("for 0 <=x<=1")
raizf = metodonewton(ff,fflin,1,0.00001,10)

print("for 3 <=x<=4")
raizf1 = metodonewton(ff,fflin,3,0.00001,10)

print("for 6 <=x<=7")
raizf2 = metodonewton(ff,fflin,6,0.00001,10)


print(raiz)

print(raiza)

print(raizb)

print(raizc)

print(raizd)

print(raizd1)

#print(raize)

print(raize1)

print(raizf)

print(raizf1)

print(raizf2)
