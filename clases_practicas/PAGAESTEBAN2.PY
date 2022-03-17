def generar_palabra():
    # Retorna una palabra al azar desde una lista de palabras
    # No se preocupe por comprender cómo esta función hace su trabajo
    from random import choice
    lista = ["pandemia","programación","paralelepipedo","equilatero","panaderia","automatizacion"] # lista de palabras en minúsculas, sin tildes ni otros símbolos
    palabra = choice(lista)
    return palabra

def palabra_encriptada(palabra):
    encri = ""
    for x in palabra:
        encri+="_ "  # se cambia la letra de la palabra por un guión bajo y un espacio
    return encri

# Escriba aquí su implementación de la función verificar_letra
def verificar_letra(palabra, letra):
    enc= palabra.find(letra)
    if enc!=-1:
        return True
    else:
        return False
    
    
# Escriba aquí su implementación de la función mostrar_letra
def mostrar_letra(palabra, encri, letra):
    lista=encri.split(' ')
    encriptada=''.join(lista)
    
    print(encriptada)
    indice= palabra.index(letra)
    encriptada=encriptada.replace(encriptada[indice],palabra[indice])
    print(encriptada)
    


# Programa principal:
if __name__ == "__main__":
    print("Bienvenidos al juego del adivinador de palabras!!!")
    palabra=generar_palabra()
    encri=palabra_encriptada(palabra)
    letra=input('introduce una letra')
    ver=verificar_letra(palabra,letra)
    if ver==True:
        mostrar_letra(palabra, encri, letra)
    
    # Complete aquí el programa que implementa el juego

    print("Fin del juego")