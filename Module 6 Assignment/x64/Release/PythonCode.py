import re
import string

x = 10

def PrintTable():
    print("Something")

def DoubleValue(v):
    return v * 2

def MultiplicationTable(v):
    global x
    x = v
    for i in range(1, 11):
        result = x * i
        print(str(x) + " X " + str(i) + " = " + str(result))
    return x

