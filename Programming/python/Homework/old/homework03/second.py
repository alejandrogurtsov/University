n, m = map(int, input().split())
ad = [input().strip() for _ in range(n)]
t = [list(map(int, input().split())) for _ in range(n)]

color={
    '.':0,
    'B':1,
    'G':2,
    'R':4,
}

flag = True
for i in range(n):
    for j in range(m):
        c = ad[i][j]
        need = color[c]
        if need != 0 and (t[i][j] & need) == 0:
            flag = False
            break
    if not flag:
        break

print("YES" if flag else "NO")