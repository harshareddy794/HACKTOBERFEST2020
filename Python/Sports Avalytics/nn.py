import keras
from keras.models import Sequential
from keras.layers import Dense

import pandas as pd
import numpy as np

dataset = pd.read_csv("sample_data.csv")
X = dataset.drop(["Date","Referee"],axis=1)

Y = dataset["FTR"]

X_train = X[0:15]
X_test = X[15:]
Y_train = Y[0:15]
Y_test = Y[15:]

model = Sequential();

firstLayer = Dense(units = 16, activation='relu', kernel_initializer='uniform',input_dim = 20)

model.add(firstLayer);

secondLayer = Dense(units = 1, activation = 'relu', kernel_initializer = 'uniform')

model.add(secondLayer);

model.compile(optimizer = 'adam', loss = 'mse', metrics=['accuracy'])

history = model.fit(X_train, Y_train, epochs = 300, batch_size = 50)

import matplotlib.pyplot as plt

plt.plot(history.history['accuracy'])
plt.title('Model accuracy')
plt.ylabel('Accuracy')
plt.xlabel('Epoch')
plt.legend(['Train', 'Test'], loc='upper left')
plt.show()

plt.plot(history.history['loss'])
plt.title('Model loss')
plt.ylabel('Loss')
plt.xlabel('Epoch')
plt.legend(['Train', 'Test'], loc='upper left')
plt.show()

