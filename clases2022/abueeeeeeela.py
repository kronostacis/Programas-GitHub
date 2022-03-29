def cantidad_unos(numero):
    numero_1 = 0
    numero_2 = 0
    mas_unos = 0
    for i in range(0, numero//2+1):
        digito_1 = i
        digito_2 = numero-i

        binarios_digito1 = format(digito_1,'b')
        binarios_digito2 = format(digito_2,'b')

        total_unos = str(binarios_digito1).count('1') + str(binarios_digito2).count('1')

        print("{0} ({2}) + {1} ({3}) = {4} unos en total".format(str(digito_1),str(digito_2),str(binarios_digito1),str(binarios_digito2),str(total_unos)))

        if total_unos > mas_unos:
            numero_1 = digito_1
            numero_2 = digito_2
            mas_unos = total_unos
        
    print("La mayor cantidad de unos se da en la suma entre {0} y {1}, con un total de {2} unos.".format(str(numero_1),str(numero_2),str(mas_unos)))

if __name__ == '__main__':
    cantidad_unos(16)