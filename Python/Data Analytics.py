import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

#leo la base de datos
dataf = pd.read_csv('/20221013_ted_talks.csv')

#relleno los datos NaN con 0
dataf = dataf.fillna(0)



#MATPLOTLIB: Muestro la comparativa entre visualizaciones y likes
likes = dataf['likes'].sum()
views = dataf['views'].sum()
datos = pd.DataFrame([likes, views], index=("ME GUSTA", "VISUALIZACIONES"))
suma = datos.sum(axis=1)
plt.bar(suma.index, suma)
plt.show()



#obtengo los maximos valores de cada columna del dataframe y los almaceno en un dato del tipo pandas.Series
maximos = dataf.max()

#para cada columna del dataframe
for columna in dataf.columns:
  
  #almaceno en una variable el maximo de la columna
  maximo_columna = maximos.get(columna)
  
  #si el maximo de la columna pasado a string no es 'None'
  if(str(maximo_columna) != 'None'):

    #guardo en una variable solo el dato del dataframe correspondiente al maximo de la columna.
    dato = dataf.loc[dataf[columna] == maximo_columna]

    #imprimo a qué columna corresponde y los distintos valores del dato.
    print('Charla TED con mayor ' + columna + ": " + str(maximo_columna))
    print('\n\n')
    print(dato.to_string())
    print('\n\n')
