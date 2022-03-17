#Regresion Lineal Simple
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

def leer(archivo):
    chile=[]
    years = []
    hidro=[]
    archivo=open(archivo,'r')
    for linea in archivo:
        linea=linea.rstrip('\n')
        split=linea.split(',')
        if linea.count('Chile')==1:
            chile.append(linea)
        if split[0]=='Chile':
            years.append(int(split[2]))
            hidro.append(float(split[5]))
    archivo.close()
    return years, hidro 
 
def  desarrollo(years,hidro):
    x_graf=np.empty((len(years),1))
    y_graf=np.empty((len(years),1))
    aux=0
    for index,elem in enumerate(hidro):
        x_graf[aux][0]=years[index]
        y_graf[aux][0]=elem
        aux=aux+1
    from sklearn.model_selection import train_test_split
    x_train, x_test, y_train, y_test = train_test_split(x_graf, y_graf, test_size=1/4, random_state=0)
    from sklearn.linear_model import LinearRegression
    regressor=LinearRegression()
    regressor.fit(x_train,y_train)

    y_pred=regressor.predict(x_test)
    plt.scatter(years, hidro, color = 'red')
    plt.plot(x_test, y_pred, color = 'blue')
    plt.title('Electricidad generada por hidroelectrica en Chile')
    plt.xlabel('years')
    plt.ylabel('Electricity from hydro')
    plt.show()
if __name__ == '__main__':
    years,hidro =leer(r'Electricity_Production_By_Source.csv')
    desarrollo(years,hidro)
    