"""n=1001000
aux=0
i=0
while n>0:
    c=n%10
    aux=aux+c*2**i
    print(aux)
    i=i+1
    n=n//10 """

"""numero=3 
i=0
while i<7:
    numero=numero+ -1 +i 
    print(numero)
    i=i+1"""


numero=11
cum=0
while numero > 0 :
    if numero % 3 != 0:
        cum=cum+(numero//4) 
    else:
        cum=cum+(numero//2)
    numero=numero-2
print(cum)
