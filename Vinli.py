# -*- coding: utf-8 -*-
"""
Created on Sat Sep 19 16:36:35 2015

@author: Camilo
"""

from firebase import firebase
import datetime

firebase = firebase.FirebaseApplication('https://tcdisrupt.firebaseio.com', None)
#result = firebase.get('/users', None)


firebase.get('/users', None,
                 params={'print': 'pretty'},
                 headers={'X_FANCY_HEADER': 'very fancy'})

data = {'name': 'Cam Busc', 'age': 26,
            'created_at': datetime.datetime.now()}

snapshot = firebase.post('/users', data)
print(snapshot['name'])

print result
#
#f = firebase.FirebaseApplication('https://tcdisrupt.firebaseio.com', None)
#r = f.post({'user_id': 'Cam', 'text': 'Hello'})


print("firebase")