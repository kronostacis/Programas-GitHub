def primo(num1):
    for x in range (1,num1):
        if (num1%x==0 and x!=num1 and x!=1):
            return False
    return num1


def llena_lista_primos(nro):
    primos = []
    for i in range(2, nro):
        if primo(i) :
            primos.append(i)
    return primos


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
    return resulta


def restabinario():
    numero=binToInt()
    numero2=binToInt()
    resultado=numero-numero2
    resulta=binario(resultado)
    print('El resultado es: ', resulta)
    print("--------------------------------")
    return resulta


def multibinario():
    numero=binToInt()
    numero2=binToInt()
    resultado=numero*numero2
    resulta=binario(resultado)
    print('El resultado es: ', resulta)
    print("--------------------------------")
    return resulta


def sumaoctal():
    numero=input('Introduce el primer octal: ')
    numero2=input('Introduce el segundo octal: ')
    suma=oct(int(numero,8)+int(numero2,8))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")
    
    
def restaoctal():
    numero=input('Introduce el primer octal: ')
    numero2=input('Introduce el segundo octal: ')
    suma=oct(int(numero,8)-int(numero2,8))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")
    
    
def multioctal():
    numero=input('Introduce el primer octal: ')
    numero2=input('Introduce el segundo octal: ')
    suma=oct(int(numero,8)*int(numero2,8))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")
    
    
def sumahexade():
    numero=input("Introduce el Primer Hexadecimal: ")
    numero2=input("Introduce el Segundo Hexadecimal: ")
    suma=hex(int(numero,16)+int(numero2,16))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")
    
    
def restahexade():
    numero=input("Introduce el Primer Hexadecimal: ")
    numero2=input("Introduce el Segundo Hexadecimal: ")
    suma=hex(int(numero,16)-int(numero2,16))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")
    
    
def multihexade():
    numero=input("Introduce el Primer Hexadecimal: ")
    numero2=input("Introduce el Segundo Hexadecimal: ")
    suma=hex(int(numero,16)*int(numero2,16))
    print('El resultado es: ',suma[2:])
    print("--------------------------------")


if __name__ == '__main__':
    