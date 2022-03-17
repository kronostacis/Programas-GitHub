def entrada(archivo):
    archivo=open(archivo)
    sopa=[]
    for linea in archivo:
        linea=linea.rstrip('\n')
        sopa.append(linea)
    
    return sopa


#funcion para leer de izquierda a derecha
def leerLtoR(sopa):
        for c in range(6):
            for i in range(7,19):
                res=str(sopa[c]).count(sopa[i])
                if res==1:
                    print(sopa[i],'a sido encontrada')
#funcion para leer de derecha a izquierda        
def leerRtoL(sopa):
        for c in range(6):
            for i in range(7,19):
                res=str(sopa[c][::-1]).count(sopa[i])
                if res==1:
                    print(sopa[i],'a sido encontrada')               
                    
def leervertical(sopa):
    p1=''
    p2=''
    p3=''
    p4=''
    p5=''
    p6=''
    list=[]
    
    for c in range(6):
        p1=p1+sopa[c][0]
    list.append(p1)
    for c in range(6):
        p2=p2+sopa[c][1]
    list.append(p2)
    for c in range(6):
        p3=p3+sopa[c][2]
    list.append(p3)
    for c in range(6):
        p4=p4+sopa[c][3]
    list.append(p4)
    for c in range(6):
        p5=p5+sopa[c][4]
    list.append(p5)
    for c in range(len(list)):
            for i in range(7,19):
                res=str(list[c]).count(sopa[i])
                if res==1:
                    print(sopa[i],'a sido encontrada')
    for c in range(len(list)):
            for i in range(7,19):
                res=str(list[c][::-1]).count(sopa[i])
                if res==1:
                    print(sopa[i],'a sido encontrada')
if __name__ == '__main__':
    entrada("e:\Programas GitHub\clases_practicas\sopa.txt")
    #leerLtoR(entrada("e:\Programas GitHub\clases_practicas\sopa.txt"))
    #leerRtoL(entrada("e:\Programas GitHub\clases_practicas\sopa.txt"))
    leervertical(entrada("e:\Programas GitHub\clases_practicas\sopa.txt"))
    