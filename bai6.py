import math

t = int(input())
for _ in range(t):
    a = input().strip()
    b = input().strip()
    print(math.gcd(int(a), int(b)))
