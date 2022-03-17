#Proyectos Números Primos en tiempos de pandemia.
#Programacion Seccion 3 
#Hecho por Vicente Maximiliano Lorca Caballero y Renato Izquierdo Conde
#Esta funcion define los números primos.
def primo(num1):
    for x in range (1,num1):
        if (num1%x==0 and x!=num1 and x!=1):
            return False
    return num1
#Esta funcion llena la lista primos desde el 2 hasta el 232
def llena_lista_primos(nro):
    primos = []
    for i in range(2, nro):
        if primo(i) :
            primos.append(i)
    return primos
#Esta lista nos devuelve los factores primos de un valor dado.
def factores(numero, primos):
    divisibles=[]
    while numero > 1:
        if primo(numero):
            divisibles.append(numero)
            break
        for i in range(len(primos)):
            if numero % primos[i] == 0:
                divisibles.append(primos[i])
                numero = numero // primos[i]
            break
    return divisibles
#Esta función lee el archivo y crea dos listas, una de dividendos y otra de divisores
def leer(archivo):
    archivo=open(archivo, 'r')
    divisor=[]
    dividendo=[]
    aux=1
    for linea in archivo:
        linea=linea.rstrip('\n')
        if aux==1:
            dividendo.append(linea)
            aux=2
        else:
            divisor.append(linea)
            aux=1
#Aca eliminamos los espacios de las listas dividendo y divisor para poder empezar a calcular        
    dividend=[]
    for i in range(0,len(dividendo)):
        dividend.append(dividendo[i].replace(' ',''))

    divis=[]        
    for i in range(0,len(divisor)):
        divis.append(divisor[i].replace(' ',''))
    
    archivo.close()
    return dividend,divis
#Esta funcion transforma las listas en enteros.
def division(dividend,divis):
    ldivisor=list(divis)
    ldividendo=list(dividend)
    divisor_ent=1
    dividendo_ent=1
#Aca se transforma la nomenclatura de Primolandia a la nuestra y se resuelve el problema.
    for i in range(0,(len(ldivisor)//2)):
        divisor_ent=divisor_ent*int(ldivisor[2*i])**int(ldivisor[2*i+1])
        
    for i in range(0,(len(ldividendo)//2)):
        dividendo_ent=dividendo_ent*int(ldividendo[2*i])**int(ldividendo[2*i+1])
#Aca nos dice el resultado si la division es exacta osea que tiene resto 0 sino nos muestra el mensaje de NO DIVISIBLE.     
    if dividendo_ent%divisor_ent==0:
        resultado=dividendo_ent//divisor_ent
        return resultado
    
    else:
        return 'NO DIVISIBLE'

#Esta función transforma el resultado de división en la nomenclatura de Primolandia.        
def primolandia(factores):
    factores.sort(reverse=True)
    traduccion=''
    for count,l in enumerate(factores):
        if l != factores[count-1] or count==0:
            potent=factores.count(l)
            traduccion = traduccion + str(l) + ' ' + str(potent) + ' '
    return traduccion

#Esto es el Código Principal.
if __name__=='__main__':
    dividendo,divisor=leer('primos.txt')
    primos=llena_lista_primos(232)
    #Aqui se escriben los resultados de la función división en un archivo resultado.txt
    salida=open('resultado.txt','w')
    for count,l in enumerate(dividendo):
        resultado=division(l,divisor[count])
        if resultado=='NO DIVISIBLE':
            salida.write('{0}\n'.format(resultado))
        else:
            factor=factores(resultado,primos)
            salida.write('{0}\n'.format(primolandia(factor)))
    salida.close()