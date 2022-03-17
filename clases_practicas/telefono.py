"""
● El alfabeto inglés contiene 26 caracteres y los teléfonos móviles
sólo tienen diez dígitos en el teclado.
● Varias letras se utilizan de forma que se pueda escribir un
mensaje con pulsaciones repetitivas. Por ejemplo, para insertar
el carácter B, se deberá presionar 22.
● Para introducir una secuencia de dos caracteres a partir de la
misma tecla, el usuario debe hacer una pausa antes de pulsar el
botón una segunda vez. Por ejemplo, 2 2 indica AA mientras que
22 indica B (se muestra un "carácter de espacio" para indicar
una pausa).
● Debe crear un programa que calcule la secuencia de teclas que
hay que pulsar para escribir un cierto mensaje.

"""
def telef(cadena):
    dicc={ "a":"2", "b":'22', "c":'222', "d":'3', "e":'33',"f":'333', "g":'4', "h":'44', "i":'444', "j":'5', "k":'55',"l":'555', "m":'6', "n":'66', "o":'666', "p":'7', "q":'77',"r":'777', "s":'7777', "t":'8', "u":'88', "v":'888', "w":'9','x':'99',"y":'999',"z":'999',' ':' ' }
    cadena=cadena.lower()
    ListaCadena=list(cadena)
    conversion=''
    for i in ListaCadena:
        conversion=conversion+dicc[i]+' '
    return conversion
if __name__ == '__main__':
    cadena = input("introduce: ")
    print(telef(cadena)) 