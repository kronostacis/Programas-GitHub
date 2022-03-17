dicc={"a":".-","b":"-..." ,"c":"-.-." ,"d":"-.." ,"e":"." ,"f":"..-." ,"g":"--." ,"h":"...." ,"i":".." ,"j":".---" ,"k":"-.-" ,"l":".-.." ,"m":"--" ,"n":"-." ,"o":"---" , "p":".--.","q":"--.-" ,"r":".-." ,"s":"..." ,"t":"-" ,"u":"..-" ,"v":"...-" ,"w":".--" ,"x":"-..-","y":"-.--" ,"z":"--..",' ':' '}
dicc1={".-":"a","-...":"b" , "-.-.":"c","-..":"d" , ".":"e","..-.":"f" ,"--.":"g" ,"....":"h" ,"..":"i" ,".---":"j" ,"-.-":"k" ,".-..":"l" , "--":"m","-.":"n" ,"---":"o" ,".--.":"p" , "--.-":"q",".-.":"r" , "...":"s", "-":"t", "..-":"u", "...-":"v",".--":"w" ,"-..-":"x" ,"-.--":"y" ,"--..":"z",'':''}
def ToMorse(cadena):
    lista=list(cadena)
    conve=''
    for i in lista:
        conve=conve+dicc[i]+' '
    print(conve)
    return conve
def Toes(cadena):
    lista=cadena.split(' ')
    conve=''
    for i in lista:
        conve=conve+dicc1[i]+' '
    print(conve)
    return conve
if __name__=='__main__':
    print('introdusca 1 si quiere de es a morse')
    print('introdusca 2 si quiere de morse a es')
    num=(input())
    if num=='1':
        cadena=input("introduzca cadena: ")
        ToMorse(cadena)
    elif num=='2':
        cadena=input("introduzca cadena: ")
        Toes(cadena)
    else:
        print('Lo introducido es erroneo')