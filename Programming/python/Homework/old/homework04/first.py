def stat(name,packets):
    print(f'Ping statistic for {name}:')
    received = len(packets)
    lost = 4-received
    lost_procent=lost*25
    print(f'Packets: Sent = 4 Recieved = {received} Lost = {lost} ({lost_procent}% loss)')
    print(f'Approximate round trip times:')
    minimum=min(packets)
    maximum=max(packets)
    average=sum(packets)//received
    print(f'Minimum = {minimum} Maximum = {maximum} Average = {average}')

packets=[]
name = input().split(' ')[1]
for p in range(4):
    line = input()
    if line=='Time out':
        continue
    packets.append(int((line.split('='))[1]))
stat(name,packets)