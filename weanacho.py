ejercise= '(5/6 + -4/8) x (9/5 – (12/5 x 6/4))' #input("")

ejercise= ejercise.replace('x','*')
ejercise= ejercise.replace('–','-')
    
split=ejercise.split(') ')

print(split)
contador=0
'''while contador<len(split):
    if split[contador].count('(')>0:
        split[contador]=split[contador].replace('(','')
    if split[contador].count(')')>0:
        split[contador]=split[contador].replace(')','')
    contador= contador+1
print(split)'''
    