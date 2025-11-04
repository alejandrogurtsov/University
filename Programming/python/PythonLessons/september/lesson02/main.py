import random
n,m = map(int, input().split())
l = [(sum([random.randint(1,12) for j in range(m)]),i) for i in range(n)]
print(*max(l))