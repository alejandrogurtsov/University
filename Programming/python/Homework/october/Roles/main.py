roles = []
text=[]
with open('roles.txt', 'r') as file:
    for line in file:
        line = line.strip()
        if ':' in line:
            break
        if line:
            roles.append(line)
    for line in file:
        line = line.strip()
        if line:
            text.append(line)

replicas = {role: [] for role in roles}

role = 0
for i, line in enumerate(text, start=1):
    if ':' in line:
        name, words = line.split(':',1)
        name = name.strip()
        words = words.strip()
        role = name

        if name in replicas:
            replicas[name].append(f'{i}) {words}')
    else:
        if role and role in replicas:
            replicas[role][-1] += ' ' + line.strip()

for role in replicas:
    print(f"{role}:")
    for line in replicas[role]:
        print(line)
    print()