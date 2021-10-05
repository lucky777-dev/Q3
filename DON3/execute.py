#!/usr/bin/python3
#coding:utf-8

import sqlite3
import os

td = input("File name to execute?: ")

if not os.path.exists(os.getcwd() + f"/data.db"):
    print(f"error: can't find file 'data.db'!")
    exit(0)

with open(td, 'r') as file:
    data = file.readlines()

if len(data) == 0:
    print(f"error: 'data.db' file is empty!")
    exit(0)

if not os.path.exists(os.getcwd() + f"/{td}"):
    print(f"error: can't find file '{td}'!")
    exit(0)

with open(td, 'r') as file:
    data = file.readlines()

cmds = []

for line in data:
    if line[1:] == ':' and line[:1].isdigit():
        cmds.append(cmd)
        cmd = ""
    elif line != "" and line != '\n':
        cmd = cmd + f"\n{line}"
    
print("Commands loaded")

cpt = 1
for cmd in cmds:
    print(f"Number {cpt}:\n{cmd}\nResult:\n")
    c.execute(cmd)
    cpt += 1

#Connects to database (creates it if it doesn't exists)
con = sqlite3.connect("data.db")

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