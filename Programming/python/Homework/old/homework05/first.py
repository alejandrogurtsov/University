n=int(input())
slov={}
for i in range(n):
    sr=str(input()).split(' ')
    cities = sr[1:]
    for city in cities:
        slov[city] = sr[0]
print(slov)
m=int(input())
l=(input().split(' '))

for city in l:
    print(slov[city])