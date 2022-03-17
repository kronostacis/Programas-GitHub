"""

Un mensaje ha llegado al mail con errores, diseñe un programa que sea capaz de 
corregir estos correos defectuosos, donde el sistema ha reemplazado 
erróneamente los espacios por comas y las comas por ‘#’.
Un ejemplo de mensaje erróneo es:
 “La,cantimplora,se,calentó#tomar,agua,así,no,tiene,gracia”


"""
def correc(mensaje):
    mensaje = mensaje.replace(',',' ')
    mensaje = mensaje.replace("#",', ')
    print(mensaje)


if __name__ == '__main__':
    mensaje = 'La,cantimplora,se,calentó#tomar,agua,así,no,tiene,gracia'
    correc(mensaje)