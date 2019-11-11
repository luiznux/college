x = [ 1 , 1.1 , 1.3 , 1.5 , 1.9 , 2.1 ]
y = [ 1.84 , 1.96 , 2.21 , 2.45 , 2.94 , 3.18]

#x = [4 , 4.2, 4.5, 4.7 ,5.1 , 5.5 , 5.9, 6.3 , 6.8 ,7.1]
#y = [102.56 , 113.18, 130.11, 142.05, 167.53, 195.14, 224.87, 256.73, 299.50, 326.72]

sumx = 0
sumy = 0
sumx2 = 0
sumxy = 0

for i in range(len(x)):
  sumx += x[i]
print("somatoria de x =",sumx)

for i in range(len(x)):
  sumy += y[i]
print("somatoria de y =",sumy)

for i in range(len(x)):
  sumx2 += (x[i]*x[i])
print("somatoria de x² =",sumx2)


for i in range(len(x)):
  sumxy += (x[i]*y[i])
print("somatoria de x*y =", sumxy)

print("Valor de M =",len(x))

a0 = ((sumx2*sumy)-(sumxy*sumx)) / ((len(x)*(sumx2)) - (sumx*sumx))
print("A0 = ",a0)

a1 = ( (len(x)*sumxy)-(sumx*sumy) ) / ( (len(x)*sumx2)- (sumx*sumx) )
print("A1 = ",a1)


print("a equação da reta é: ", "%.4f" % a1,"X+", "%.4f" % a0)



