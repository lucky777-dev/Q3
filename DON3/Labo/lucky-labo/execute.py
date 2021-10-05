#!/usr/bin/python3
#coding:utf-8

import sqlite3
import os

if not os.path.exists(os.getcwd() + f"/data.db"):
    print(f"error: can't find file 'data.db'!")
    exit(0)

td = input("File name to execute?: ")

if not os.path.exists(os.getcwd() + f"/{td}"):
    print(f"error: can't find file '{td}'!")
    exit(0)

with open(td, 'r') as file:
    content = [line.rstrip() for line in file.readlines()]
    #content = file.readlines()
    
if len(content) == 0:
    print(f"error: '{td}' file is empty!")
    exit(0)

cmds = []
cmd = ""

for line in content:
    print(cmd)
    if line[1:] == '.' and line[:1].isnumeric():
        if int(line[:1]) > 1:
            print("ok")
            print(cmd)
            cmds.append(cmd)
            cmd = ""
    elif line != "" and line != '\n':
        if cmd == "":
            cmd = cmd + f"{line}"
        else:
            cmd = cmd + f" {line}"
            print(cmd)
            
cmds.append(cmd)
print(cmds)
print("Commands loaded")

#Connects to database (creates it if it doesn't exists)
con = sqlite3.connect("data.db")

#Create cursor
c = con.cursor()

cpt = 1
for cmd in cmds:
    c.execute(cmd)
    print(f"Number {cpt}:\n|{cmd}|\nResult:\n{c.fetchall()}")
    cpt += 1