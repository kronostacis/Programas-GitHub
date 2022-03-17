###  RNN Regresion

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import tensorflow as tf

#Importacion de datos
df = pd.read_excel('./Borrador.xlsx', sheet_name='Borrador')
df.info()
df.head(5)



###Limpieza de datos###
df.isnull().sum() #Verificamos si hay valores nulos en alguna columna del dataframe
#Eliminar variables que tienen un alto porcentaje de registros con el valor nulo
df_var = df.isnull().sum() #Creamos una serie de pandas con el número de valores nulos de cada variable
porcentaje_eliminacion = 0.1 #10% de registros de una columna tiene nulos, no se considera la variable
df_var = df_var[df_var<porcentaje_eliminacion*len(df)] #Nos quedamos con las variables que tienen menos de un porcentaje de registros nulos
lista_variables_OK = df_var.index #Nos quedamos con el índice de la serie (los nombres de las variables de interés)
df = df[lista_variables_OK] #Filtramos el dataframe original y nos quedamos solo con las columnas de interés
df.head(5)

#Eliminamos registros que tienen algún valor nulo
df.dropna(inplace=True)  #fila con valores nulos, se elimina por completo
df.isnull().sum() #Verificamos si hay valores nulos en alguna columna del dataframe

#Datos Estadisticos de mi df
df.describe().transpose() #Principales datos estadísticos del dataframe

#Visualizacion del df
plt.figure(figsize=(12,8))
sns.distplot(df['Peso secado']) #variable objetivo
sns.countplot(df['Peso alimentacion'])  #Grafico de variables de entrada 
#Plantearse descartar outliers para facilitar 
#el entrenamiento de la red neuronal si suponen alta carga computacional o elevado error del modelo

#Buscar correlaciones
df.corr()['Peso secado'].sort_values() #Verificar qué variables tienen mayor correlación con la salida
#sort_values() deja la lista de menor a mayor 

#Visualizacion de variables correlacionadas con la salida
plt.figure(figsize=(12,8))
sns.scatterplot(x='Peso secado',y='Promedio Presion membrana aire',data=df)   #graficos de dispersion
sns.boxplot(x='Peso alimentacion',y='Peso secado',data=df)       #grafico de cajas y bigotes

# Objetivo: Eliminar variables que no tienen ninguna relación con la variable objetivo 
# o bien su información ya está incluida en otras variables 
# Aprovechar conocimiento del campo que estamos tratando
df = df.drop(['C','Ciclo','Ciclo','Promedio Presion Aire secado','Std Presion Aire secado','Std Flujo aire secado',
              'Tiempo total ciclo','Tiempo total prensado','Tiempo total secado',
              'Promedio Flujo aire secado','Std Presion membrana aire','Tiempo diferencia 0.75% alim',
              'Tiempo diferencia 1.00% alim'],axis=1) #Variables a eliminar.
df.head()   #Ver df



###Division Train / Test
X = df.drop('Peso secado',axis=1)  #Variables de entrada, menos la variable de salida
y = df['Peso secado']              #Variable de salida

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2,random_state=101)



###Escalado 
#Para que la red no otorgue pesos mayores a algunas variables que tienen ordenes de magnitud mayores a otras.
from sklearn.preprocessing import MinMaxScaler
scaler = MinMaxScaler()
X_train= scaler.fit_transform(X_train)
X_train
X_test = scaler.transform(X_test)
X_test


###Creacion del modelo###
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Activation
from tensorflow.keras.optimizers import Adam
import tensorflow as tf

model = Sequential()
#Es recomendado añadir un número de neuronas similar al número de entradas en X_train en el ejemplo
num_neuronas = X_train.shape[1]
#num_neuronas = 200
model.add(tf.keras.layers.Dense(units=6, activation='sigmoid', input_shape=(6, )))
#model.add(Dense(num_neuronas,activation='relu'))
#model.add(Dense(num_neuronas,activation='relu'))
#model.add(Dense(num_neuronas,activation='relu'))
#model.add(Dense(num_neuronas,activation='relu'))
#model.add(Dense(1))             # Indicar tantas neuronas de salida como variables a predecir
model.add(tf.keras.layers.Dense(units=1, activation='linear')) #otra manera de capa de salida

#Buscar mejor funcion de activacion para capa de salida sigmoid? o linear?
model.summary()
model.compile(optimizer='adam',loss='mse')


###Entrenamiento###
model.fit(x = X_train, y = y_train.values,
          validation_data=(X_test,y_test.values), batch_size=32,epochs=1000) 

#validation_data: en cada epoch calcula sobre el conjunto de test el resultado de pérdidas
#batch_size: es el tamaño de datos que toma en cada cálculo (Recomendado potencia de 2)
#epochs: es el número de iteraciones sobre la red neuronal para ajustar los pesos (w) y bias (b)
losses = pd.DataFrame(model.history.history)  
losses
losses.plot()



###Evaluacion del modelo###
from sklearn.metrics import mean_squared_error,mean_absolute_error,explained_variance_score
X_test
predictions = model.predict(X_test)
mean_absolute_error(y_test,predictions)
np.sqrt(mean_squared_error(y_test,predictions))
explained_variance_score(y_test,predictions) #Calcula la covarianza en y_test (real) y la predicción,
# cuanto más cercano a 1 mejor (significa que conforme más aumenta o disminuye el valor real, más aumenta o disminuye el valor predecido)

#¿En qué porcentaje nos estamos equivocando respecto al valor medio?
mean_absolute_error(y_test,predictions)/df['Peso secado'].mean() 

#¿En qué porcentaje nos estamos equivaocando respecto al valor mediana?
mean_absolute_error(y_test,predictions)/df['Peso secado'].median()

# Visualizar nuestra predicción
plt.scatter(y_test,predictions)
plt.xlabel("Valor Real")
plt.ylabel("Predicción")
# Predicción perfecta
plt.plot(y_test,y_test,'r')

#evaluar el error
errors = y_test.values.reshape(y_test.shape[0], 1) - predictions 
#rotar y_test para poder comparar con predictions

sns.distplot(errors) #Idealmente debe estar concentrado el error en 0



###Prediccion con nuevos datos###
#Lectura datos a predecir
df_pred = pd.read_excel('./Pred.xlsx',sheet_name='Hoja1')
#Filtramos el dataframe predicción para quedarnos con las mismas columnas de interés que el df histórico
df_pred = df_pred[df.columns] #df es nuestro data frame original (inicio)
df_pred

X_pred = df_pred.drop('Peso secado',axis=1) 
#Eliminamos la columna objetivo (vacía) si la hubiera en nuestro df con los datos a predecir
X_pred

X_pred = scaler.transform(X_pred)
X_pred

#Realizamos predicción
resultado = model.predict(X_pred)
resultado

#Unimos en un dataframe los datos a predecir con su predicción
df_pred['PREDICCIÓN']=pd.DataFrame(resultado)
df_pred



###Opcional para guardar y cargar el modelo###
#Guardar y cargar el modelo para posterior uso
#from tensorflow.keras.models import load_model
#model.save('modelo_regresion.h5')
#Cargar modelo para posterior uso
#modelo_cargado = load_model('modelo_regresion.h5')















