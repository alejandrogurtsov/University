w, h = map(int,input().split())
n = int(input())
l=[[0 for j in range(w)] for i in range(h)]

if n>1:
    for i in range(n):
        x1, y1, x2, y2 = map(int, input().split())
        for _x in range(x1,x2):
            for _y in range(y1, y2):
                l[_y][_x]=1
else:
    x1, y1, x2, y2 = map(int, input().split())
    for _x in range(x1, x2):
        for _y in range(y1, y2):
            l[_y][_x] = 1
c=0
for row in l:
    c+=row.count(0)
print(c)