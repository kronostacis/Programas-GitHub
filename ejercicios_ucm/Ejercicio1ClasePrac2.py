"""
Realice un programa que lea tantas cadenas de String como el usuario 
indique por teclado, a continuación, para cada cadena separe cada palabra 
por espacio (“ ”) y muestre en pantalla dos mensajes:
○ El primero contiene todas las palabras que ocupan una posición impar 
en el texto.
○ El segundo contiene todas las palabras que ocupan una posición par en 
la el texto.
● Ejemplo: “Hugo y Philip somos sus profes”
○ Mensaje 1: “Hugo Philip sus”
○ Mensaje 2: “y somos profes”

"""

def separador_impar(cadena):
    cadena=cadena.split(" ")
    
    for i in range(0,(len(cadena)),2):
        print(cadena[i])
def separador_par(cadena):
    cadena=cadena.split(" ")
    for i in range(1,(len(cadena)),2):
        print(cadena[i])
    

if __name__ == '__main__':
    i = int(input('introduce la cantidad de cadenas de strings: '))
    c=0
    while c < i:
        string_final=input('introduce un string: ')
        print("--------------------")
        print("Forma Impar:")
        separador_impar(string_final)
        print("--------------------")
        print("Forma Par:")
        separador_par(string_final)
        c=c+1   

    