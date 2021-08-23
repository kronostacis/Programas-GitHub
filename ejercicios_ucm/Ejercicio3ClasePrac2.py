"""
Cree un programa donde se ingrese una cadena de String y entregue el 
porcentaje de letras vocales que posee, del total de vocales entregue el 
porcentaje de aparición de cada vocal y muestra cual es la vocal con mayor 
frecuencia de la cadena

"""
def porcentaje(cadena):
    lista=[]
    a=cadena.count('a')
    e= cadena.count('e')
    i= cadena.count('i')
    o= cadena.count('o')
    u=cadena.count('u')
    suma=a+e+i+o+u
    print(len(cadena))
    print(suma)
    """lista.append(a)
    lista.append(e)
    lista.append(i)
    lista.append(o)
    lista.append(u)
    aux=0
    for elem in lista:
        if elem>aux:
            aux=elem
        print(aux)"""

    print(len(cadena))
    print(suma)
    print("el porcentaje de vocales del total de la cadena es: ",(suma*100)/len(cadena))
    print("el porcentaje de aparicion de a es: ",(a*100)/suma,"%")
    print("el porcentaje de aparicion de e es: ",(e*100)/suma,"%")
    print("el porcentaje de aparicion de i es: ",(i*100)/suma,"%")
    print("el porcentaje de aparicion de o es: ",(o*100)/suma,"%")
    print("el porcentaje de aparicion de u es: ",(u*100)/suma,"%")
    if a>e and a>i and a>o and a>u:
        print("la vocal con mayor frecuencia de la cadena es: a")
    elif e>a and e>i and e>o and e>u:
        print("la vocal con mayor frecuencia de la cadena es: e")
    elif i>e and i>a and i>o and i>u:
        print("la vocal con mayor frecuencia de la cadena es: i")
    elif o>e and o>i and o>a and o>u:
        print("la vocal con mayor frecuencia de la cadena es: o")
    elif u>e and u>i and u>o and u>a:
        print("la vocal con mayor frecuencia de la cadena es: u")

















if __name__ == '__main__':
    cadena = input("introduce la cadena: ")
    porcentaje(cadena)