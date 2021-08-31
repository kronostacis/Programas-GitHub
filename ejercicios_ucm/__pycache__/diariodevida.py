"""Cree un programa donde sea posible ingresar una página de diario de vida,
el programa deberá comprobar que el escrito cumpla con los siguientes
estándares mínimos:
○ La primera palabra del escrito debe comenzar con mayúscula.
○ La primera palabra luego de un punto seguido deberá comenzar con
mayúscula."""

def mayuscula(texto):
    parte=texto.split(". ")
    for l in range(len(parte)):
        
        if texto[0].isupper():
            if parte[l].islower():
                parte[l]=parte[l].capitalize()
            else:
                return True
        else:
            texto=texto.capitalize()
            if parte[l].islower():
                parte[l]=parte[l].capitalize()
            else:
                return True
    print(parte)

if __name__ == '__main__':
    cadena = input("introduce una cadena: ")
    mayuscula(cadena)
    if mayuscula==True:
        print("Es correcto")