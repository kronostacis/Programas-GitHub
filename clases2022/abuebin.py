'''

Emilia es una niña con suerte, su abuela Ximena es una encantadora anciana,
propietaria de una parcela. Emilia le pide frutos secos (pistachos, maníes, nueces,
etc), pero su sabia abuelita le permite comer cantidades limitadas para cuidar de su
salud.
Ximena es aficionada a los números binarios, así que le propuso el siguiente juego a
Emilia: la abuelita dirá un número N, y Emilia escogería dos números (x e y), tales
que la suma de ambos debe dar N. Entonces, Ximena daría a Emilia tantos frutos
secos como la cantidad de unos que tengan x e y en base 2. Por ejemplo, si Ximena
propone 7 y Emilia escoge 3 y 4, recibiría 3 frutitas (3 es (11)2 y 4 es (100)2
).
Emilia quisiera saber la máxima cantidad de frutitas que podría obtener de Ximena.
La entrada del programa será un número N, la salida será una lista de todos los
posibles casos que cumplen con las restricciones descritas, seguida del caso donde
Emilia recibe más frutos secos.

'''

def binario(numero):
    a=format(numero, "b")
    return a
def abueli(N):
    lista=[]
    max=[]
    for x in range(1,(N)):
        lista.append(x)
    for x in range(len(lista)):
        for i in range(len(lista)):
            if x+i==N:
                binx=str(binario(x))
                biny=str(binario(i))
                concat=binx+biny
                contar=concat.count('1')
                max.append(contar)
    max.sort()
    print('La maxima cantidad de frutas a obtener son {0}'.format(max[-1]))            
if __name__ == '__main__':
    abueli(16)
    