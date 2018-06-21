# Create your first MLP in Keras
import os
os.environ['TF_MIN_GPU_MULTIPROCESSOR_COUNT'] = '5'
os.environ['CUDA_VISIBLE_DEVICES'] = '-1'
from keras.models import Sequential
from keras.layers import Dense
from keras.wrappers.scikit_learn import KerasRegressor
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import KFold
from sklearn.preprocessing import StandardScaler
from sklearn.pipeline import Pipeline
import numpy as np
import pandas as pd
from keras import backend as K
from sklearn.metrics import mean_squared_error
from math import sqrt

def root_mean_squared_error(y_true, y_pred):
        return K.sqrt(K.mean(K.square(y_pred - y_true), axis=-1)) 


# define the model
def larger_model():
	# create model
    model = Sequential()
    model.add(Dense(128, input_dim=8, kernel_initializer='normal',  activation='relu'))
    model.add(Dense(64, kernel_initializer='normal', activation='relu'))
    model.add(Dense(32, kernel_initializer='normal', activation='relu'))
    model.add(Dense(8, kernel_initializer='normal', activation='relu'))
    model.add(Dense(1, kernel_initializer='normal'))
	# Compile model
    model.compile(loss= root_mean_squared_error, optimizer='adam')
    return model


# fix random seed for reproducibility
seed = 7
np.random.seed(seed)
data = pd.read_csv('Concrete_Data.csv', encoding = "ISO-8859-1", header=None)
num_of_cols = data.shape[1]
y = data.iloc[:, num_of_cols - 1]
X = data.iloc[:,0:num_of_cols-1]
# create model
estimators = []
holder =  KerasRegressor(build_fn=larger_model, epochs=150, batch_size=5, verbose=1, shuffle = False)
estimators.append(('standardize', StandardScaler()))
estimators.append(('mlp', holder))
pipeline = Pipeline(estimators)


kfold = KFold(n_splits=10, random_state=seed)
results = cross_val_score(pipeline, X, y, cv=kfold)
holder.fit(X,y,  epochs = 150, batch_size = 5)
score = sqrt(mean_squared_error(y, holder.predict(X, batch_size = 5, verbose = 0)))

print("Root Mean Squared Error:           %.15f " % (abs(results.mean())))
print("Training RMSE:                     %.15f" % score)




