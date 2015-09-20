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

resp = requests.get(url, auth=(user, password))
#pprint.pprint(resp.json())

#63f16cad-7224-4d4b-a95b-557359f40887

#GET https://telemetry.vin.li/api/v1/devices/27a2ac50-d7bd-11e3-9c1a-0800200c9a66/messages
url2 = 'https://telemetry.vin.li/api/v1/devices/63f16cad-7224-4d4b-a95b-557359f40887/messages?limit=100'
resp2 = requests.get(url2, auth=(user, password))
data_dict = resp2.json()
#print(data)
#pprint.pprint(resp2.json())
#requests
#data.popitem(" )
#print type(data)
#print len(data)

#for key in data.keys():
#  print key
#
#print data['messages']
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

#for item in locations:
#    if item.get('locations', {}):  
#        cordinates.append('cordinates': item.get('locations', {}).get('cordinates'))
        
print(speeds)
print(locations)
print(cordinates)

for x in range(0,100):
    fuelLevelData.append(100-x)
    
print(fuelLevelData)     

snapshot = firebase.put('https://tcdisrupt.firebaseio.com', 'currentSpeedData', speeds)
snapshot = firebase.put('https://tcdisrupt.firebaseio.com', 'locations', locations)
snapshot = firebase.put('https://tcdisrupt.firebaseio.com', 'fuelLevelData', fuelLevelData)
#    
#for item in data:​
#    if item.get('data', {}):
#        speeds.append({'speed': item.get('data', {}).get('vehicleSpeed')})
        
        
        
        
#
#json_data= json.dumps(data['messages'])
#print type(json_data)
#pdata = dict(json.loads(json_data))
#print type(pdata)
#print pdata



#
#for key in data.iteritems() :
#    print data['vehicleSpeed']
#json1_data = json.load(data)

#print(json1_data)

## simple wrapper function to encode the username & pass
#def encodeUserData(user, password):
#    return "Basic " + (user + ":" + password).encode("base64").rstrip()
#
## create the request object and set some headers
#req = urllib2.Request(url) 
#req.add_header('Accept', 'application/json')
#req.add_header("Content-type", "application/x-www-form-urlencoded")
#req.add_header('Authorization', encodeUserData(u, p))
## make the request and print the results
#res = urllib2.urlopen(req)
#print res.read()
#
#subprocess.call(["curl"])
#conn = httplib.HTTPSConnection("https://platform.vin.li", 443)
#
#conn.request("curl -u c87d5be0-2e69-11e4-8c21-0800200c9a66:HKLFFoSILb8VHFJD https://platform.vin.li/api/v1/devices","/")
##conn.request("CURL", "/api/v1/devices", "-u 33e3ba78-b4a5-424d-bc5a-f9a27448349b:CXkuiUqtDuy7M5QDso6tSQAM")
###conn.setRequestProperty("Accept", "application/json");
#r1 = conn.getresponse()
#print r1.status, r1.reason
#
#data1 = r1.read()
#print data1
#
#
#print result
#
#f = firebase.FirebaseApplication('https://tcdisrupt.firebaseio.com', None)
#r = f.post({'user_id': 'Cam', 'text': 'Hello'})


print("firebase")

#
#>>> import httplib
#>>> conn = httplib.HTTPSConnection("www.python.org")
#>>> conn.request("GET", "/")
#>>> r1 = conn.getresponse()
#>>> print r1.status, r1.reason
#200 OK
#>>> data1 = r1.read()
#>>> conn.request("GET", "/")
#>>> r2 = conn.getresponse()
#>>> print r2.status, r2.reason
#404 Not Found
#>>> data2 = r2.read()
#>>> conn.close()
#
#>>> import requests
#>>> user = '33e3ba78-b4a5-424d-bc5a-f9a27448349b'
#>>> password = 'CXkuiUqtDuy7M5QDso6tSQAM'
#>>> url = 'https://platform.vin.li/api/v1/devices'
#>>> 
#>>> 
#>>> resp = requests.get(url, auth=(user, password))
#>>> resp.json
#KeyboardInterrupt
#>>> import pprint
#>>> pprint.pprint(resp.json())
#{u'devices': [],
# u'meta': {u'pagination': {u'limit': 20,
#                           u'links': {u'first': u'https://platform.vin.li/api/v1/devices?offset=0&limit=20',
#                                      u'last': u'https://platform.vin.li/api/v1/devices?offset=0&limit=20'},
#                           u'offset': 0,
#                           u'total': 0}}}