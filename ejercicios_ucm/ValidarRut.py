def calculo_dv(rut):
    parte=rut.split('-')
    parte0rut=parte[0]
    parte1rut=parte[1]
    listaPar0=list(parte0rut)
    rlistapar0=list(reversed(listaPar0))
    listaMulti=[2,3,4,5,6,7,2,3,4,5,6,7,2]
    suma=0
    for l in range(0,len(rlistapar0)):
        valor=(int(rlistapar0[l])*int(listaMulti[l]))
        suma=suma+valor
    modulo=suma%11
    rut=11-modulo
    k='k'
    if parte[1].isdigit():
        return True
    elif (not(parte[1].isdigit())) and (str(parte1rut)==k and rut==1):
        return True
    else:
        return False
    

def verifica(rut):
    guion = rut.count('-')
    if guion != 1:
        return False
    else:
        parte = rut.split('-')
        print(parte)
        if len (parte[1]) != 1:
            return False
        else:
            if parte[1] != 'k':
                if not(parte[1].isdigit()):
                    return False
                else:
                    return True
        # La primera parte
        if not(parte[0].isdigit()):
            return False
        else:
            ok1 = calculo_dv(rut)
            return ok1

#Código principal
if __name__ == '__main__':
    rut = input("RUT: ")
    ok = verifica(rut)
    if ok == True:
        print("Rut validado")
    else:
        print("Rut incorrecto")

    print ('eso es todo')
    calculo_dv(rut)
    #22127099-k