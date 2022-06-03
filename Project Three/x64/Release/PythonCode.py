import re
import string
from collections import Counter


def Frequency():
    print("Opening file grocery.txt")
    f = open ("grocery.txt")
    
    print("Reading data...")
    lines = f.readlines() #make list of strings of each line from .txt
    f.close()

    ch = "\n"
    removeNewLine = [elem.replace(ch, "") for elem in lines] #remove trailing newline character from readlines

    itemOccur = Counter(removeNewLine) #create dictionary with item and occurence pairs

    print("Creating file frequency.dat...")
    f = open("frequency.dat", "a")
    f.truncate(0)

    for key in itemOccur:
        f.write(key)
        f.write(" ")

        f.write(str(itemOccur[key]))
        f.write("\n")
    
    f.close()
    print("freqeuncy.dat file created")

def SingleItemFreq(userItem):
    f = open ("grocery.txt")
    lines = f.readlines() #make list of strings of each line from .txt
    f.close()

    ch = "\n"
    removeNewLine = [elem.replace(ch, "") for elem in lines] #remove trailing newline character from readlines

    itemOccur = Counter(removeNewLine) #create dictionary with item and occurence pairs

    return itemOccur[userItem]

def ListItemFreq():
    print("Opening file grocery.txt")
    f = open ("grocery.txt")
    
    print("Reading data...")
    lines = f.readlines() #make list of strings of each line from .txt
    f.close()

    ch = "\n"
    removeNewLine = [elem.replace(ch, "") for elem in lines] #remove trailing newline character from readlines

    itemOccur = Counter(removeNewLine) #create dictionary with item and occurence pairs
    print(itemOccur)