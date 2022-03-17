def reemplazoTilde(cadena):
    cadena = cadena.lower()
    cadena=cadena.replace('á','a')
    cadena=cadena.replace('é','e')
    cadena=cadena.replace('í','i')
    cadena=cadena.replace('ó','o')
    cadena=cadena.replace('ú','u')
    cadena=cadena.replace('ñ','n')
    return cadena

def pangrama(texto):
    lista=["a", "b", "c", "d", "e","f", "g", "h", "i", "j", "k","l", "m", "n", "o", "p", "q","r", "s", "t", "u", "v", "w",'x',"y","z"]
    suma=0
    for l in lista:
        bool=texto.count(l)
        if bool!=0 and bool>0:
            suma=suma+1
        else:
            return False
    
    if suma==26:
        return True
    else:
        return False
def esPangrama(num):
    i=1
    while i<=num:
        cadena=input('introduce una cadena: ')
        reemplazoTilde(cadena)
        if pangrama(cadena)==True:
            print('Es un pangrama')
        else:
            print('No es un pangrama')
        i=i+1

if __name__ == '__main__': 
    cant=int(input("cantidad de cadenas: "))
    esPangrama(cant)