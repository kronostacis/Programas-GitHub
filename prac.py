#sopa=['dofgo','barco','oluza','tctia','enapx','yates']
#p=sopa[0][0]+sopa[1][0]+sopa[2][0]+sopa[3][0]
#print(p)

def abrir(archivo):
    archivo=open(archivo)
    sopa=[]
    for linea in archivo:
        linea=linea.rstrip('\n')
        sopa.append(linea)
    print(sopa)
    return sopa

if __name__ == '__main__':
    abrir("e:\Programas GitHub\clases_practicas\sopa_entrada.txt")