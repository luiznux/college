import pdb
import msvcrt 

#pdb.set_trace()

print ("press 'Esc' to quit...")

while 1:
    # se tiver uma tecla pressiona
    if msvcrt.kbhit():
        #pega a tecla
        key = msvcrt.getch()
        print(key)
        #imprime codigo ascii e caractere
        print(str(ord(key))+"="+chr(ord(key)))
        # se codigo ascii igual a esc=27 sai do laco
        if ord(key) == 27:
            break;

print("fim de programa")
    
