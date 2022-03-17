# Creado Por:
# Benjamin Villablanca Zuniga
# Esteban Rojas Calderon

def lectura(archivo):
    linea=[]
    archivo=open(archivo, 'r')
    for line in archivo:
        line=line.rstrip('\n')
        linea.append((line))
    archivo.close()
    return linea

def primo(num1):
    for x in range (1,num1):
        if (num1%x==0 and x!=num1 and x!=1):
            return False
    return num1

def llena_lista_primos(nro):
    primos = []
    for i in range(2, nro):
        if primo(i):
            primos.append(i)
    return primos

def factores(numero, primos):
    divisibles=[]
    while numero > 1:
        if primo(numero):
            divisibles.append(numero)
            break
        for i in range(len(primos)):
            if numero % primos[i] == 0:
                divisibles.append(primos[i])
                numero = numero // primos[i]
                break
    divisibles.sort()
    divisibles=list(reversed(divisibles))
    return divisibles

def desarrollo(lista):
    divisor=[]
    loquesedivide=[]
    l=1
    contador=0
    for i in lista:
        split=i.split(' ')
        # aqui usamos el range para ver los pares e impares y asi ver lo que es base de lo que es exponente
        for e in range(int(len(split)/2)):
            b = int(split[2*e])**int(split[2*e+1])
            l=l*b    
        # aca usamos el contador para ver si tiene que ir en la lista de dividendo o divisor
        if contador ==0:
            loquesedivide.append(l)
            l=1
            contador=1
        else:
            divisor.append(l)
            l=1
            contador=0             
    division=[]
    for i in range(len(divisor)):
        division.append(loquesedivide[i]/divisor[i])
    
    return loquesedivide,divisor,division

def salida(dividendo,divisor,divisiones):
    sal=open('resultado.txt','w')
    lista=[]
    texto=''
    #Aca vemos si el numero es un entero y si lo es lo agrego a lista, si no digo que es igual a 0 y lo agrego a la lista 
    for i in range(len(divisiones)):
        if dividendo[i]%divisor[i] == 0:
            a=int(divisiones[i])
            lista.append(a)
        else:
            lista.append(0)
    #aca sacamos los factores primos de la lista que contiene las divisiones y si es 0 significa que no es division entera  
    for a in lista:
        if a !=0:
            text=factores(a, primos)
            #aqui hacemos lo que va a aparecer en la salida 
            for index,t in enumerate(text):
                #este if hace que si se repite el numero no lo ponga en la salida repetidas veces
                if (t!=text[index-1]) or (index==0):
                    if text.count(t)==1:
                        texto=texto+(str(str(t) + ' 1')+' ')
                    else:
                        texto=texto+str(t)+" "+str(text.count(t))+' '
        if a == 0:
            texto=texto+'NO DIVISIBLE'
        texto=texto+'\n'
    sal.write(texto)
    sal.close()

if __name__ == "__main__":
    lista=lectura(r"primos.txt")
    dividendo,divisor,divisiones=desarrollo(lista)
    primos = llena_lista_primos(232)
    salida(dividendo,divisor,divisiones)