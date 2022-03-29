
import matplotlib.pyplot as plt
listay=[]
listax=[]
listam2=[]
for i in range(-5,5):
    y=(((-2/3)*i)-5/6)
    m2=(((3/2)*i))
    listax.append(i)
    listay.append(y)
    listam2.append(m2)

plt.plot(listax,listay)
plt.plot(listax,listam2)
plt.show()
    