import random

def generate_string(n0, n1, n2):
    arr = []
    for i in range(0, n0):
        arr.append("0")
    for i in range(0, n1):
        arr.append("1")
    for i in range(0, n2):
        arr.append("2")
    for i in range(0, 5):
        random.shuffle(arr)
    str = ""
    for i in range(0, len(arr)):
        str = str + arr[i]
    return str

file = open("test_parameters.txt")
with open("test_strings.txt", "w") as myfile:
    for line in file:
        n0 = 0
        n1 = 0
        n2 = 0
        split = line.split(" ")
        n0 = int(split[0])
        n1 = int(split[1])
        n2 = int(split[2])
        str = generate_string(n0, n1, n2)
        myfile.write(str + "\n")
