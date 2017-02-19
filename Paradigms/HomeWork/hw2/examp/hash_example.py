from hashlib import sha512

h1, h2 = sha512(), sha512()
with open(__file__, "rb") as f:
    chunk_size = 4096
    chunk = f.read(chunk_size)
    while chunk:
        h1.update(chunk)
        h2.update(chunk)
        chunk = f.read(chunk_size)

print(h1.hexdigest())
print(h1.digest())
print(hash(h1))

print(h2.hexdigest())
print(h2.digest())
print(hash(h2))

d = {h1: 1, h2: 2}

if h1 == h2:
    print("Equal")
