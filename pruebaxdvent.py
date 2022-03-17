import pandas as pd   
import os 
fullpath=r'E:\Programas GitHub\ventiladores_ocupados.csv'
data=pd.read_csv(fullpath)
print(data.head())