l1=[int(x1) for x1 in input().split()]
l2=[int(x2) for x2 in input().split()]
print([i[1]-i[0] for i in zip(l1,l2)])