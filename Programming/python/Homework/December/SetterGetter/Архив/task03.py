class IPAddress:
    def __init__(self, ipaddress):
        if isinstance(ipaddress, str):
            parts = ipaddress.split(".")
            if len(parts) != 4:
                raise ValueError("Неверный формат")
            try:
                parts = [int(p) for p in parts]
            except ValueError:
                raise ValueError
        elif isinstance(ipaddress, (list,tuple)):
            if len(ipaddress) != 4:
                raise ValueError
            parts = []
            for p in ipaddress:
                if not isinstance(p, int):
                    raise ValueError
                parts.append(p)

        else:
            raise ValueError

        for p in parts:
            if not (0 <= p <= 255):
                raise ValueError

        self.parts = parts

    def __str__(self):
        return ".".join(str(p) for p in self.parts)

    def __repr__(self):
        return f"IPAddress('{str(self)}')"

ip1 = IPAddress("91.125.31.2")
ip2 = IPAddress([56, 29, 1, 5])

print(ip1)
print(ip2)

print(repr(ip1))
print(repr(ip2))
