"""Realice un programa que solicite al usuario una cadena String y, a
continuación, solicite al usuario un recorte de cadena en un intervalo
específico (desde la posición 1 hasta el largo del String).
● Por ejemplo, si se ingresa “Philip quiere que aprendan mucho”, con el
intervalo 5 a 15, el resultado será:
“ip quiere “
*Acomode el intervalo de valores, ya que Python comienza las posiciones desde el 0."""

def corte(cadena):
    a=int(input("inicio: "))
    b=int(input("final: " ))
    print(cadena[a-1:b-1])

if __name__ == '__main__':
    cadena=input("introduce cadena a cortar: ")
    print("desde que largo hasta que largo de la cadena quiere: ")
    corte(cadena)