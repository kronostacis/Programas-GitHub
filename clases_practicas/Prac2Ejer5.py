'''

● Realizar un programa donde se solicite una cadena al usuario, a 
continuación, el programa imprimirá la cadena invertida caracter a caracter y 
una cadena invertida en grupos de 4 caracteres.
● Ejemplo:
○ Entrada: “Ingeniería en la UCM” 
○ Salida: “ MCU al ne aíreinegnI”
 “ UCMn laía enierInge”


'''

def inv(cadena):
    inv=cadena[::-1]
    print(inv)

if __name__ == '__main__':
    cadena='Ingeniería en la UCM'
    inv(cadena)


