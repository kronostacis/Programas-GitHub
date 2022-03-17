# Creado Por Benjamin Villablanca
# esta funcion es para el menu
def menu():
    print("Menu de operaciones")
    print("1. Suma")
    print("2. Resta")
    print("3. Multiplicacion")
    print("4. Salir")
    op = input ("Escriba la opcion:")
    print("--------------------------------")
    op = int(op)
    if op==1: suma()
    elif op==2: resta()
    elif op==3: multi()
    else: exit()
    
def binario(numero):
    a=format(numero, "b")
    if len(a)==2:
        a="00"+a
    elif len(a)==3:
        a="0"+a
    elif len(a)==1:
        a="000"+a
    return a

def binToInt():
    numero=int(input('introduce numero: '))
    leng=1000
    posición=[]
    for i in range(1,leng):
        a=format(i, "b")
        posición.append(a)
    for i in posición:
        if int(i) == numero:
            indexer=posición.index(i)+1
            break
    return indexer
    
def sumabinario():
    numero=binToInt()
    numero2=binToInt()
    resultado=numero+numero2
    resulta=binario(resultado)
    print('El resultado es: ', resulta)
    print("--------------------------------")
    menu()
    return resulta

def restabinario():
    numero=binToInt()
    numero2=binToInt()
    resultado=numero-numero2
    resulta=binario(resultado)
    print('El resultado es: ', resulta)
    print("--------------------------------")
    menu()
    return resulta

def multibinario():
    numero=binToInt()
    numero2=binToInt()
    resultado=numero*numero2
    resulta=binario(resultado)
    print('El resultado es: ', resulta)
    print("--------------------------------")
    menu()
    return resulta

def sumaoctal():
    numero=input('Introduce el primer octal: ')
    numero2=input('Introduce el segundo octal: ')
    suma=oct(int(numero,8)+int(numero2,8))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")
    menu()
def restaoctal():
    numero=input('Introduce el primer octal: ')
    numero2=input('Introduce el segundo octal: ')
    suma=oct(int(numero,8)-int(numero2,8))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")
    menu()
    
def multioctal():
    numero=input('Introduce el primer octal: ')
    numero2=input('Introduce el segundo octal: ')
    suma=oct(int(numero,8)*int(numero2,8))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")
    menu()
    
def sumahexade():
    numero=input("Introduce el Primer Hexadecimal: ")
    numero2=input("Introduce el Segundo Hexadecimal: ")
    suma=hex(int(numero,16)+int(numero2,16))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")
    menu()
    
def restahexade():
    numero=input("Introduce el Primer Hexadecimal: ")
    numero2=input("Introduce el Segundo Hexadecimal: ")
    suma=hex(int(numero,16)-int(numero2,16))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")
    menu()
    
def multihexade():
    numero=input("Introduce el Primer Hexadecimal: ")
    numero2=input("Introduce el Segundo Hexadecimal: ")
    suma=hex(int(numero,16)*int(numero2,16))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")
    menu()

def suma():
    print('Que base quiere?')
    print("1. Suma de base binario")
    print("2. Suma de base octal")
    print("3. Suma de base hexadecimal")
    op = input ("Escriba la opcion:")
    op = int(op)
    if op==1: sumabinario()
    elif op==2: sumaoctal()
    elif op==3: sumahexade()

def resta():
    print('Que base quiere?')
    print("1. Resta de base binario")
    print("2. Resta de base octal")
    print("3. Resta de base hexadecimal")
    op = input ("Escriba la opcion:")
    op = int(op)
    if op==1: restabinario()
    elif op==2: restaoctal()
    elif op==3: restahexade()

def multi():
    print('Que base quiere?')
    print("1. Multiplcacion de base binario")
    print("2. Multiplcacion de base octal")
    print("3. Multiplcacion de base hexadecimal")
    op = input ("Escriba la opcion:")
    op = int(op)
    if op==1: multibinario()
    elif op==2: multioctal()
    elif op==3: multihexade()
    
if __name__ == '__main__':
    menu()
    