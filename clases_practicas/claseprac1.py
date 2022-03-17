'''
Crear un programa donde se creén las siguientes cadenas:
● “El valor de una idea radica en el Uso de la misma”
● “El hombre es el único Animal que come Sin tener hambre bebe Sin tener sed y 
habla Sin tener nada que decir”
● “Eres lo que haces No lo que dices que vas a Hacer”
A continuación, responda:
¿Determinar cuántos caracteres “a” y “e” posee cada cadena?
¿Cuantas palabras mezclan mayúsculas y minúsculas en cada cadena?
¿Cuantas palabras comienzan con minúsculas en cada cadena?
'''
def cantidaddeletras(cadena):
    a=cadena.count('a')
    e=cadena.count('e')
    print(a+e)
    
def mayus(cadena):
    cadena=cadena.split(' ')
    conta=0
    for i in range(len(cadena)):
        if cadena[i][0].isupper():
            conta=conta+1
    print(conta)        
            
def minus(cadena):
    cadena=cadena.split(' ')
    conta=0
    for i in range(len(cadena)):
        if cadena[i][0].islower():
            conta=conta+1
    print(conta)        



if __name__ == '__main__':

    cadena1='El valor de una idea radica en el Uso de la misma'
    cadena2='El hombre es el único Animal que come Sin tener hambre bebe Sin tener sed y habla Sin tener nada que decir'
    cadena3='Eres lo que haces No lo que dices que vas a Hacer'
    
    cantidaddeletras(cadena1)
    cantidaddeletras(cadena2)
    cantidaddeletras(cadena3)
    mayus(cadena1)
    mayus(cadena2)
    mayus(cadena3)
    minus(cadena1)
    minus(cadena2)
    minus(cadena3)