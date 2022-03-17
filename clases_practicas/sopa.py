def entrada(archivo):
    sopa=[]
    pos=0
    archivo=open(archivo)
    for elem in archivo:
        elem=elem.rstrip('\n')
        if(pos==0):
            tamano=elem
            tamano=tamano.split(" ") #6 5,    15 10
            filas=int(tamano[0])
            columnas=int(tamano[1])
        if(pos>0 and pos<filas):
            sopa.append(elem)
        if(pos==filas ):
            sopa.append(elem) 
        
        pos=pos+1
    return sopa

def encontrar(archivo):
    buscar=[]
    pos=0
    archivo=open(archivo)

    for elem in archivo:
        elem=elem.rstrip('\n')
        if(pos==0):
            tamano=elem
            tamano=tamano.split(" ") #6 5,    15 10
            filas=int(tamano[0])
            columnas=int(tamano[1])
        if(pos>filas+1):
            buscar.append(elem)
        pos=pos+1
        
    return buscar
    
def leerLtoR(sopa,buscar):
        a=''
        #count=0
        for c in range(len(sopa)):
            for i in range(len(buscar)):
                res=str(sopa[c]).count(buscar[i])
                if res==1:
                    #count=count+1
                    #print(buscar[i],'a sido encontrada')
                    # a para imprimir en salida.txt
                    a=a+(buscar[i]+' encontrada'+"\n")     
        #print(count)    
        return a     

def leerRtoL(sopa,buscar):
    #count=0
    a=''
    for c in range(len(sopa)):
            for i in range(len(buscar)):
                res=str(sopa[c][::-1]).count(buscar[i])
                if res==1:
                    #count=count+1
                    #print(buscar[i],'a sido encontrada')
                    a=a+(buscar[i]+' encontrada'+"\n")
    #print(count)                                
    return a

#leer en vertical
def leervertical(sopa,buscar):
    
    #p1 variable que contiene la palabra en vertical
    p1=''
    list=[]
    a=''
    #count=0
    #range 5 por que llega hasta 5 cada palabra de la sopa 
    for i in range(len(sopa[0][:])):   
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
                    #count=count+1
                    #print(buscar[i],'a sido encontrada')
                    a=a+(buscar[i]+' encontrada'+"\n")
                else:
                    pass
                             
    for c in range(len(list)):
            for i in range(len(buscar)):
                res=str(list[c][::-1]).count(buscar[i])
                if res==1:
                    #count=count+1
                    #print(buscar[i],'a sido encontrada')
                    a=a+(buscar[i]+' encontrada'+"\n")
                else:
                    pass
    #print(count)                       
    return a               
    
def salida(a,b,c):
    salida=open("e:\Programas GitHub\clases_practicas\salida.txt",'w')
    salida.write(a)
    salida.write(b)
    salida.write(c)
    salida.close()

def noenc(archivo):
    salida=open("e:\Programas GitHub\clases_practicas\salida.txt",'r')
    pal=''
    pel=''
    for l in salida:
        l=l.rstrip("\n")
        pal=pal+l+' '
    salida.close()
    salida=open("e:\Programas GitHub\clases_practicas\salida.txt",'a')
    for e in range(len(archivo)):
        res=(pal).count(archivo[e])
        if res==0:
            pel=pel+(archivo[e] + ' no ha sido encontrada \n')
    salida.write(pel)
    salida.close()    
    return pel
    
if __name__ == '__main__':
    entrada("e:\Programas GitHub\clases_practicas\sopa.txt")
    e=encontrar("e:\Programas GitHub\clases_practicas\sopa.txt")
    a=leerLtoR(entrada("e:\Programas GitHub\clases_practicas\sopa.txt"),encontrar("e:\Programas GitHub\clases_practicas\sopa.txt"))
    b=leerRtoL(entrada("e:\Programas GitHub\clases_practicas\sopa.txt"),encontrar("e:\Programas GitHub\clases_practicas\sopa.txt"))
    c=leervertical(entrada("e:\Programas GitHub\clases_practicas\sopa.txt"),encontrar("e:\Programas GitHub\clases_practicas\sopa.txt"))
    d=salida(a,b,c)
    f=noenc(e)
    print("Lea el archivo de salida para ver las palabras encontradas")