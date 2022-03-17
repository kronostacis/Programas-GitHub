'''
Eres un biólogo que examina secuencias de ADN de formas de vida
diferentes. Se te darán dos secuencias de ADN, y el objetivo es encontrar el
conjunto ordenado de bases adyacentes de mayor tamaño que es común en
ambos ADNs.
● Las secuencias de ADN se darán como conjuntos ordenados de bases de
nucleótidos: adenina (A), citosina (C), guanina (G) y timina (T):
○ ATGTCTTCCTCGA TGCTTCCTATGAC
● Para el ejemplo anterior, el resultado es CTTCCT ya que es el conjunto
ordenado de bases adyacentes de mayor tamaño que se encuentra en
ambas formas de vida.
● Lea las cadenas desde un archivo
'''
import difflib
def comp(cadena, cadena2):
 
# define original text
# taken from: https://en.wikipedia.org/wiki/Internet_Information_Services
    original = [cadena]

# define modified text
    edited = [cadena2]

# initiate the Differ object
    d = difflib.Differ()
    print(str(d))
    
# calculate the difference between the two texts
    diff = d.compare(original, edited)
    
 
# output the result
    print ('n'.join(diff))

if __name__ == '__main__':
    cadena="ATGTCTTCCTCGA"
    cadena2='TGCTTCCTATGAC'
    comp(cadena, cadena2)