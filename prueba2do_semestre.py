#Programa creado por Benjamin Villablanca 21046300-3
#Seccion 2 Prueba 1 segundo semestre

import matplotlib.pyplot as plt

def leer(archivo):
    
    archivo=open(archivo,'r')
    lectura=[]
    fechas=[]
    Camas_ocupadas=[]
    
    #En este for leo el archivo linea a linea
    for linea in archivo:
        #elimino el enter con rstrip
        linea=linea.rstrip('\n')
        lectura.append(linea)
    archivo.close()
    
    for i in lectura:
        #hago un split por coma para cada linea y lo guardo en la lista para cada caso
        split=i.split(',')
        fechas.append(split[0])
        Camas_ocupadas.append(split[3])
        
    ocupadas=[]
    #hago este for para poder tener la cantidad de camas ocupadas en numeros en vez de string 
    for i in Camas_ocupadas:
        ocupadas.append(int(i))
    
    #para que no se vea la mancha lo escrivo en forma de dias y no de la fecha completa y con eso la mancha desaparece 
    dias=[]    
    for i in range(len(fechas)):
        dias.append(i)
    
    #retorno las camas ocupadas por dias y las fechas 
      
    return fechas, ocupadas
          
        
def graf(x,y):
    dias=[]    
    for i in range(len(x)):
        dias.append(i)
    plt.plot(dias,y)
    plt.show()        


def detalle(x,y):
    #aqui hago un for para ver las fechas y las camas ocupadas e imprimirlas en consola
    
    for i in range(len(x)):
        print('En esta fecha {0} habian {1} camas ocupadas'.format(x[i],y[i]))
    print('Programa finalizado con exito')
        
if __name__ == '__main__':
    
    #x son los dias. y son la cantidad de camas ocupadas y z son las fechas
    #para que funcione el programa el archivo ventiladores_ocupados.csv tiene que estar en la misma carpeta del programa o si no puede dar error
    
    x,y=leer(r'ventiladores_ocupados.csv')
    graf(x,y)
    detalle(x,y)
    