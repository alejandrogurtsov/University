txt = (str(input())).split()
for w in range(len(txt)):
    txt[w].replace('.','')
    txt[w].replace(',', '')
slov={}
for w in txt:
    slov[w]=slov.get(w,0)+1
print(slov)