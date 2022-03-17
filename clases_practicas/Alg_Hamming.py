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

def bit_trans(bits):
    
    bits='pp'+str(bits)
    bits=str(bits[:3])+'p'+str(bits[3:])
    bits=str(bits[:7])+'p'+str(bits[7:])
    lista=list(bits)
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
    
if __name__=='__main__':
    bits=100101011
    #bits=100101011
    lista=bit_trans(bits)
    posi=pos(lista)
    res,paridad0=hallar(lista,posi)
    print(res)
    bits1=101101011
    1111001101011
    #bits1=1111001101011
    lista1=bit_trans(bits1)
    posi1=pos(lista1)
    resultado,paridad1=hallar(lista1,posi1)
    comprobacionparidad=comprobacion(paridad0,paridad1)
    print(paridad0,paridad1)
    for i,value in enumerate(posi):
        if value==''.join(comprobacionparidad):
            if res[i]!=resultado[i]:
                print('El error de paridad esta en la posicion: ',i+1)