# -*- coding: utf-8 -*-
"""
Created on Sat Sep 19 16:36:35 2015

@author: Camilo
"""

from firebase import firebase
import datetime
import httplib
import subprocess
import urllib2
import requests
import pprint
import json
import time

## 33e3ba78-b4a5-424d-bc5a-f9a27448349b

## CXkuiUqtDuy7M5QDso6tSQAM

#Token
# 41_cV8vsDXw_X7GxohgelM7ars3ZSeFRJcQh16EJ__X8ESRVAsVganJY_6D21gul

firebase = firebase.FirebaseApplication('https://tcdisrupt.firebaseio.com', None)
#result = firebase.get('/users', None)


firebase.get('/users', None,
                 params={'print': 'pretty'},
                 headers={'X_FANCY_HEADER': 'very fancy'})

data = {'name': 'Cam Busc', 'age': 26,
            'created_at': datetime.datetime.now()}

##def put(self, url, name, data, params=None, headers=None, connection=None):
##firebase.
snapshot = firebase.put('https://tcdisrupt.firebaseio.com', 'Test1', data)
print(snapshot['name'])


user ='33e3ba78-b4a5-424d-bc5a-f9a27448349b'
password ='CXkuiUqtDuy7M5QDso6tSQAM'
url = 'https://platform.vin.li/api/v1/devices'

url2 = 'https://telemetry.vin.li/api/v1/devices/63f16cad-7224-4d4b-a95b-557359f40887/messages?limit=100'
resp2 = requests.get(url2, auth=(user, password))
data_dict = resp2.json()

data = data_dict['messages']
print type(data)
print len(data)

speeds = []
locations = []
cordinates = []
fuelLevelData = []

for item in data:
    if item.get('data', {}):
        speeds.append({'speed': item.get('data',{}).get('vehicleSpeed')})

for item in data:
    if item.get('data', {}):
        locations.append({'location': item.get('data',{}).get('location').get('coordinates')})
   
print(speeds)
print(locations)
print(cordinates)

for x in range(0,100):
    fuelLevelData.append(100-x)
    
print(fuelLevelData)     

snapshot = firebase.put('https://tcdisrupt.firebaseio.com', 'currentSpeedData', speeds)
snapshot = firebase.put('https://tcdisrupt.firebaseio.com', 'locations', locations)
snapshot = firebase.put('https://tcdisrupt.firebaseio.com', 'fuelLevelData', fuelLevelData)
