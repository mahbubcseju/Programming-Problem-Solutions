
n, m = map(int, input().strip().split())

ar = []

for i in range(n):
    ar += list(map(int, input().strip().split()))

val = sorted(ar)

print(sum(val) - ar[0] * ( n * m))