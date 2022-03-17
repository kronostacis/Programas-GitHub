import matplotlib.pyplot as plt
def leer(archivo):
    
    archivo = open("e:\Programas GitHub\ejercicios_ucm\TotalesNacionalesResumen.csv")
    fecha= archivo.readline()
    fecha = fecha.rstrip('\n')
    x= fecha.split(',')
    casos=archivo.readline()
    casos=casos.rstrip('\n')
    casos= casos.split(',')
    y=[]
    for elem in casos:
        y.append(float(elem))
    archivo.close()
    fe='2020-0'
    cha=3
    nro = 3
    X1 = []
    Y1 = []
    while nro <13:
        if nro <10:
            X1.append('2020-0'+str(nro))
        else:
            X1.append('2020-'+str(nro))
        nro = nro + 1
    nro = 1
    while nro <10:
        X1.append('2021-0'+str(nro))
        nro = nro + 1
    largo = len(x)
    i = 0
    ii = 0
    suma = 0
    while i < largo:
        if x[i].find(X1[ii]) != -1:
            suma = suma + y[i]
            i = i + 1
        else:
            Y1.append(suma)
            suma = 0
            ii = ii + 1
    Y1.append(suma)
    return X1, Y1
    



def graf(x,y):
    plt.bar(x, y)
    plt.show()
        

if __name__ == '__main__':
    x,y=leer("e:\Programas GitHub\ejercicios_ucm\TotalesNacionalesResumen.csv")
    graf(x,y)