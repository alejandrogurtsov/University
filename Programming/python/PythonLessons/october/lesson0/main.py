import os

# my_file.write('Hello')
# my_file.write('23')
# my_file.close()
try:
    my_file = open('text1.txt', 'r')
    s=my_file.readline()
    while s!="":
        print(s)
        s=my_file.readline()
    my_file.close()
except FileNotFoundError as fnfe:
    print('Файл не найден')
