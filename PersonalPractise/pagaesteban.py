print('De un oracion')
o=input('')
o=o.lower()
separada=o.split(' ')
salida=''
for i in separada:
    if len(i)>=6:
        #uso el replace para cambiar las vocales por un str vacio
        i=i.replace('a','')
        i=i.replace('e','')
        i=i.replace('i','')
        i=i.replace('o','')
        i=i.replace('u','')
        salida=salida+' '+i
    else:
        salida=salida+' '+i
print(salida)
