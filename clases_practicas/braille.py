braille_diccionario = {"*....." : "1", "*.*..." : "2", "**...." : "3", "**.*.." : "4", "*..*.." : "5","***..." : "6", "****.." : "7", "*.**.." : "8", ".**..." : "9", ".***.." : "0", '':''}
def leer(archivo):
    
    archivo =open(archivo)
    cantidad=int(archivo.readline())
    line=[]
    for i in range(1,4):
        line.append(archivo.readline().rstrip('\n'))
    return cantidad, line

def traducir(cant, line):
    texto=[]
    traductor=''
    lineas=''
    sal=open('sal.txt','w')
    for e in range(cant):
        for i in range(len(line)):
            split=line[i].split(' ')
            lineas=lineas+split[e]
            if len(lineas)==6:
                texto.append(lineas)
                lineas=''
    for i in texto:
        traductor=traductor+braille_diccionario[i]
    sal.write(traductor)
    print('Programa ejecutado correctamente')
    
if __name__ == '__main__':
    cant,line=leer(r"E:\Programas GitHub\clases_practicas\braille-entrada.txt")
    traducir(cant, line)