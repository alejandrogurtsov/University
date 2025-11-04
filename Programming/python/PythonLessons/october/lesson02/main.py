from ipaddress import ip_network, collapse_addresses

routes = []
with open("routes.txt") as f:
    for line in f:
        if not line.strip():
            continue
        parts = line.split()
        if len(parts) < 3:
            continue
        ip, mask = parts[1], parts[2]
        routes.append(ip_network(f"{ip}/{mask}", strict=False))

collapsed = list(collapse_addresses(routes))

with open("routes_compact.txt", "w") as out:
    for net in collapsed:
        # Ограничим агрегацию, чтобы не превышать /8
        if net.prefixlen < 8:
            net = ip_network(f"{net.network_address}/8")
        # Преобразуем маску в десятичную
        mask = str(net.netmask)
        out.write(f"route {net.network_address} {mask} net_gateway\n")

print(f"✅ Готово! Создан файл routes_compact.txt ({len(collapsed)} маршрутов)")
