l1=[int(x) for x in input().split()]

if len(l1)==1:
    print(*l1)
else:
    l2 = [l1[i - 1] + l1[(i + 1) % len(l1)] for i in range(len(l1))]
    print(*l2)