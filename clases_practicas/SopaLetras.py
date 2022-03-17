def entrada(archivo):
    archivo=open(archivo)
    sopa=[]
    for linea in archivo:
        linea=linea.rstrip('\n')
        sopa.append(linea)
    
    return sopa

def encontrar(archivo):
    archivo=open(archivo)
    buscar=[]
    for linea in archivo:
        linea=linea.rstrip('\n')
        buscar.append(linea)
    return buscar

#funcion para leer de izquierda a derecha
def leerLtoR(sopa, buscar):
        a=''
        for c in range(len(sopa)):
            for i in range(len(buscar)):
                res=str(sopa[c]).count(buscar[i])
                if res==1:
                    #print(buscar[i],'a sido encontrada')
                    # a para imprimir en salida.txt
                    a=a+(buscar[i]+' encontrada'+"\n")
                    
        return a 
        
#funcion para leer de derecha a izquierda
def leerRtoL(sopa,buscar):
    a=''
    for c in range(len(sopa)):
            for i in range(len(buscar)):
                res=str(sopa[c][::-1]).count(buscar[i])
                if res==1:
                    #print(buscar[i],'a sido encontrada')
                    a=a+(buscar[i]+' encontrada'+"\n")
                                    
    return a

#leer en vertical
def leervertical(sopa,buscar):
    #p1 variable que contiene la palabra en vertical
    p1=''
    list=[]
    a=''
    
    #range 5 por que llega hasta 5 cada palabra de la sopa 
    for i in range(5):   
        for c in range(len(sopa)):
            p1=p1+sopa[c][i]
            if len(p1)==len(sopa):
                list.append(p1)
                p1=''             
    #list=p1.split(" ")  
    for c in range(len(list)):
            for i in range(len(buscar)):
                res=str(list[c]).count(buscar[i])
                if res==1:
                    #print(buscar[i],'a sido encontrada')
                    a=a+(buscar[i]+' encontrada'+"\n")
                    
                    
    for c in range(len(list)):
            for i in range(len(buscar)):
                res=str(list[c][::-1]).count(buscar[i])
                if res==1:
                    #print(buscar[i],'a sido encontrada')
                    a=a+(buscar[i]+' encontrada'+"\n")
                    
    return a               
    
#muestra en salida.txt las palabras encontradas    
def salida(a,b,c):
    salida=open("e:\Programas GitHub\clases_practicas\salida.txt",'a')
    salida.write(a)
    salida.write(b)
    salida.write(c)
    salida.close()
    
if __name__ == '__main__':
    entrada("e:\Programas GitHub\clases_practicas\sopa_entrada.txt")
    encontrar("e:\Programas GitHub\clases_practicas\encontrar.txt")
    a=leerLtoR(entrada("e:\Programas GitHub\clases_practicas\sopa_entrada.txt"),encontrar("e:\Programas GitHub\clases_practicas\encontrar.txt"))
    b=leerRtoL(entrada("e:\Programas GitHub\clases_practicas\sopa_entrada.txt"),encontrar("e:\Programas GitHub\clases_practicas\encontrar.txt"))
    c=leervertical(entrada("e:\Programas GitHub\clases_practicas\sopa_entrada.txt"),encontrar("e:\Programas GitHub\clases_practicas\encontrar.txt"))
    salida(a,b,c)
    print("Lea el archivo de salida para ver las palabras encontradas")