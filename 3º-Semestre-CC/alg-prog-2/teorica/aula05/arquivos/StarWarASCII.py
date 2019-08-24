import msvcrt 
import time
import os


entrada = open("StarWarASCII.txt", "r")
os.system('cls')
jogoAtivo = True
while jogoAtivo:
   #le 14 linhas
   cont  = 1;
   
   while cont <= 14:
      linha = entrada.readline()
      if linha == "":
         jogoAtivo = False
         break
      
      print(linha)
      cont+=1
      #se tiver uma tecla pressiona
      if msvcrt.kbhit():
         #pega a tecla
         key = msvcrt.getch()
         # se codigo ascii igual a esc=27 sai do laco
         if ord(key) == 27:
            jogoAtivo = False #sai do laco externo
            break;  ## sai do laco interno
   
   #espera 150 milisegundos
   #para funcao sleep tempo em segundos
   print ("press 'Esc' to quit...")
   time.sleep(0.1)
   os.system('cls')
   #print("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n")
   
entrada.close()
print("---- GAME OVER ----")



