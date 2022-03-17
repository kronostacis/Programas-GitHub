'''

Escribir un programa que pida por teclado dos palabras, y a continuación, indique 
si riman o no.
● Si coinciden las tres últimas letras debe indicar que si riman.
● Si coinciden sólo las dos últimas letras debe indicar que riman un poco.
● En caso contrario, debe indicar que no riman

'''
def riman(palabra, palabra2):
    if (palabra[-1] == palabra2[-1]) and (palabra[-2] == palabra2[-2]) and (palabra[-3] == palabra2[-3]):
        print('las palabras riman')
    elif (palabra[-1] == palabra2[-1]) and (palabra[-2] == palabra2[-2] and (palabra[-3] != palabra2[-3])):
        print('las palabras riman un poco')
    else:
        print('no riman')
    
if __name__ == '__main__':
    palabra = input('Introduce Palabra: ')
    palabra2 = input('Introduce Palabra ')
    riman(palabra,palabra2)
    
    
    