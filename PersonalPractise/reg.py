import matplotlib.pyplot as plt
def leer(archivo):
    archivo=open(archivo,'r')
    archi=[]
    for linea in archivo:
        linea=linea.rstrip('\n')
        archi.append(linea)
    archivo.close()
    return archi

def maule(archi):
    maule=[]
    for i in range(len(archi)):
        if archi[i].count('Maule')!=0:
            maule.append(archi[i])
            
    comunas=[]
    casos_por_comuna=[]
    casos=[]
    
    #con el for saco la informacion que necesito para guardar en las variables casos y comunas
    
    for i in range(len(maule)):
        #para dividir y sacar la informacion que necesito
        split=maule[i].split(',')
        comunas.append(split[2])
        casos_por_comuna.append(split[5])
    for i in range(len(casos_por_comuna)):
        casos.append(float(casos_por_comuna[i]))

    return comunas,casos

#grafico de barras
def graf(x,y):
    plt.bar(x, y)
    plt.xticks(range(len(x)), x, rotation=90)
    plt.show()
    
# da la suma de casos totales en el maule    
def detalle(y):
    suma=0
    for i in y:
        suma=suma+i
    print('En las {0} comunas del Maule la suma de casos totales es: {1}'.format(len(x),suma))
    
if __name__ == "__main__":
    #aca debe de ingresarse la ruta del archivo.csv 
    archivo='E:\Programas GitHub\PersonalPractise\casos_por_region.csv'
    archi=leer(archivo)
    x,y=maule(archi)
    graf(x,y)
    detalle(y)