def digit_root(n):
    while n >= 10:
        n = sum(map(int, str(n)))
    return n

def bilet(chislo):
    for i in range(1,len(chislo)):
        part1=sum(map(int,chislo[:i]))
        part2=sum(map(int,chislo[i:]))
        if digit_root(part1) == digit_root(part2):
            return True
    return False

chislo = str(input()).strip()
schastliv = bilet(chislo)
if schastliv:
    print("YES")
else:
    print("NO")