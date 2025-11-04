n=int(input())
slov={}
for n in range(n):
    s=input().split(' ')
    slov[s[0]]=s[1]

word=input()
for i in slov:
    if i==word:
        print(slov[i])
    elif slov[i]==word:
        print(i)