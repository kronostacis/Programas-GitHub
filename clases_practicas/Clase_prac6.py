import matplotlib.pyplot as plt
def leer(archivo):
    archivo=open(archivo,'r')
    datos=[]
    for linea in archivo:
        linea=linea.rstrip('\n')
        datos.append(linea)
    
    maule=[]
    for i in range(len(datos)):
        if datos[i].count('Maule')!=0:
            maule.append(datos[i])
    
    return datos,maule

def leer2020(archivo):
    archivo=open(archivo,'r')
    datos=[]
    for linea in archivo:
        linea=linea.rstrip('\n')
        datos.append(linea)
    
    maule=[]
    for i in range(len(datos)):
        if datos[i].count('Maule')!=0:
            maule.append(datos[i])
    
    return maule

def porcentaje_maule(maule):
    info=' '.join(maule)
    informacion=info.replace(',',' ')
    maulelist=info.split(',')
    PorcentajeCasosMaule=	float(maulelist[1])*100/1033000
    PorcentajeFallecidosMaule =float(maulelist[2])*100/37445
    
    return informacion, PorcentajeCasosMaule, PorcentajeFallecidosMaule
def PosdeFallecer(archivo):
    archivo.remove(archivo[0])
    regiones=[]
    casos=[]
    muertes=[]
    for i in archivo:
        split=i.split(',')
        regiones.append(split[0])
        casos.append(split[1])
        muertes.append(split[2])
        porcentajes=[]
    for i in range(len(regiones)):
         porcentajes.append(float(muertes[i])*100/float(casos[i]))
    maximo=max(porcentajes)
    pos=porcentajes.index(maximo)   
    resultado='la region con mas posibilidad de muerte es: '+ regiones[pos]+' '+'con una probabilidad de '+ str(maximo)
    return casos,regiones,resultado
    
def porce2020(maule1,maule2):
    split2021=maule1[0].split(",")
    split2020=maule2[0].split(",")
    muertes2021=int(split2020[2])
    muertes2020=int(split2021[7])
    porcentaje=muertes2021*100/muertes2020
    return str(porcentaje)    
    
def salida(info, porcentaje1,porcentaje2,posibilidad,porce2020):
    archivo=open('E:\Programas GitHub\clases_practicas\salidaprac6.txt','w')
    informacion=info.split(' ')
    archivo.write('Region = {0}\nCasos totales acumulados= {1}\nFallecidos totales= {2}\nCasos confirmados recuperados={3}\nCasos confirmados por antigeno={4}\nCasos con sospecha de reinfeccion= {5}\nCasos probables acumulados={6}\nCasos activos probables={7}\nCasos nuevos totales={8}\nCasos nuevos con sintomas={9}\nCasos nuevos sin sintomas*={10}\nCasos nuevos reportados por laboratorio={11}\nCasos nuevos confirmados por antigeno={12}\nCasos activos confirmados={13}\n'.format(informacion[0],informacion[1],informacion[2],informacion[3],informacion[4],informacion[5],informacion[6],informacion[7],informacion[8],informacion[9],informacion[10],informacion[11],informacion[12],informacion[13]))
    archivo.write('El porcentaje da casos de Maule con respecto a Chile es: '+str(porcentaje1)+'\n')
    archivo.write('El porcentaje de fallecidos en Maule con respecto al total de fallecidos en chile: '+str(porcentaje2)+'\n')
    archivo.write(posibilidad +'\n')
    archivo.write('el porcentaje de muertes del 2021 con respecto al 2020 es: '+porce2020)
    archivo.close()


#grafico de barras
def graf(x,y):
    casos=[]
    for i in y:
        casos.append(float(i))
  
    plt.bar(x, casos)
    plt.xticks(range(len(x)), x, rotation=90)
    plt.show()

if __name__ == '__main__':
    datos,maule=leer('E:\Programas GitHub\clases_practicas\covid.csv')
    maule2=leer2020('E:\Programas GitHub\clases_practicas\covid2020.csv')
    x,y,z=porcentaje_maule(maule)
    casos,regiones,pos=PosdeFallecer(datos)
    porce2020_2021=porce2020(maule,maule2)
    salida(x,y,z,pos,porce2020_2021)
    graf(regiones,casos)
    
    
