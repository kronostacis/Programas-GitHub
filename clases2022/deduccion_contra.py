"""
8.- Deducción de contraseña: se solicita un algoritmo para deducir contraseñas
basadas en una lista de los primeros 25 números primos, las contraseñas a deducir
son las siguientes:
● Pedro: su contraseña es una concatenación de los primeros 5 números
primos que se encuentran en posiciones impares ordenados de manera
decreciente.
● Juan: su contraseña es una concatenación de los primeros 5 números
primos que se encuentran en posiciones pares ordenados de manera
creciente.
● Diego: su contraseña es una concatenación de los primeros 5 números
primos que se encuentran en posiciones primas ordenados de manera
creciente

"""

def primo(num1):
    for x in range(1,num1):
        if (num1%x==0) and x!=num1 and x!=1:
            return False
    return num1
def lista(len):
    lista=[]
    for x in range(2,len):
        if primo(x):
            lista.append(x)
    return lista

def pedro(primos):
    contraseña=""
    reprimos=list(reversed(primos))
    for i in range(0,len(primos)):
        if i%2==1:
            contraseña+=str(reprimos[i])
    return contraseña

def juan(primos):
    contraseña=""
    for i in range(0,len(primos)):
        if i%2==0:
            contraseña+=str(primos[i])
    return contraseña

def diego(primos):
    contraseña=""
    for i in primos:
        contraseña+=str(primos[i])
        print(primos[i])
    return contraseña

if __name__ == "__main__":
    primos=lista(30)
    pedrocon=pedro(primos)
    juancon=juan(primos)
    print(primos)
    print(diego(primos))
    