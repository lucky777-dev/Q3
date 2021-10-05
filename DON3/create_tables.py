#!/usr/bin/python3
#coding:utf-8

import sqlite3
import os

if not os.path.exists(os.getcwd() + "/gcuv"):
    print("error: can't find file 'gcuv'!")
    exit(0)

with open("gcuv", 'r') as file:
    data = file.readlines()

if len(data) == 0:
    print("error: 'gcuv' file is empty!")
    exit(0)

#Connects to database (creates it if it doesn't exists)
con = sqlite3.connect("new.db")

#Create cursor
c = con.cursor()

#Create a table in db
#--------------------
c.execute("""CREATE TABLE employe (empno TEXT,
                                   empnom TEXT,
                                   empsexe TEXT,
                                   empsal INTEGER,
                                   empdpt TEXT)""")
c.execute("""CREATE TABLE departement (dptno TEXT,
                                       dptlib TEXT,
                                       dptmgr TEXT,
                                       dptadm INTEGER)""")
print("Database created")

for cmd in data:
    if cmd != "" and cmd != '\n':
        c.execute(cmd)

print("Success!")