def separar(nombre_archivo, año):
    lista=[]
    abrir=open(nombre_archivo)
    contador=0
    salida=''
    sumapesos=[]
    for x in abrir:
        if contador>0:
            x=x.rstrip("\n")
            x=x.split(",")
            print(x[0])
            
            if x[0].count(str(año))>0:
                archivo=open(x[1]+'_'+str(año)+'.txt','w')
                salida+=(str(x)+'\n')
                sumapesos.append(float(x[3]))
                
        contador+=1              
    archivo.write(salida)
    archivo.write(str(sumapesos))
if __name__ == '__main__':
    (separar(r'E:\Programas GitHub\buques.txt', 2020))