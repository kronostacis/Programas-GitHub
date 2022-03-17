def bit_trans(bit):
    count=1
    posicion=1
    x=0
    hamming=[]
    bits=list(str(bit))
    while x<len((bits)):
        if posicion==count:
            hamming.append("p")
            posicion*=2
        else:
            hamming.append(bits[x])
            x+=1
        count=count+1
    return hamming

def pos(bits):
    leng=len(bits)
    posición=[]
    for i in range(1,leng+1):
        a=format(i, "b")
        if len(a)==2:
            a="00"+a
        elif len(a)==3:
            a="0"+a
        elif len(a)==1:
            a="000"+a
        posición.append(a)
    return posición

def paridad(bits):
    contador=bits.count(str(1))
    if contador%2==0:
        return str(0)
    elif contador%2!=0:
        return str(1)
def comprobacion(paridad0,paridad1):
    lista=[]
    for i in range(len(paridad0)):
        if paridad0[i]==paridad1[i]:
            lista.append('0')
        elif paridad0[i]!=paridad1[i]:
            lista.append('1')
    return lista

def hallar(lista,posición):
    p1=''
    p2=''
    p3=''
    p4=''
    for e in range(len(posición)):
        if posición[e][3]==str(1):
            p1=p1+str(lista[e])
        if posición[e][2]==str(1):
            p2=p2+str(lista[e])
        if posición[e][1]==str(1):
            p3=p3+str(lista[e])
        if posición[e][0]==str(1):
            p4=p4+str(lista[e])
    p1=p1.lstrip('p')
    p2=p2.lstrip('p')
    p3=p3.lstrip('p')
    p4=p4.lstrip('p')                   
    par1=paridad(p1)
    par2=paridad(p2)
    par3=paridad(p3)
    par4=paridad(p4)
    paridad1=[par1,par2,par3,par4]
    for a in range(len(lista)):
        if a == 0:
            lista[a]=par1
        if a == 1:
            lista[a]=par2
        if a == 3:
            lista[a]=par3
        if a == 7:
            lista[a]=par4
    res=''.join(lista)
    return res, paridad1
def eliminarP(res):
    lista=list(res)
    for i in range(4):
        terminos=(2**i)-1
        lista[terminos]='p'
    res=''.join(lista)
    return lista    
if __name__ == '__main__':
    bits=100101011
    lista=bit_trans(bits)
    posi=pos(lista)
    res,paridad0=hallar(lista,posi)
    bits1='1111011101011'
    eliminar=eliminarP(bits1)
    result,paridad1=hallar(eliminar,posi)
    pe=comprobacion(paridad0,paridad1)
    print(paridad0,paridad1)
    for i,value in enumerate(posi):
        if value==''.join(pe):
            if res[i]!=result[i]:
                print('El error de paridad esta en la posicion: ',i+1)