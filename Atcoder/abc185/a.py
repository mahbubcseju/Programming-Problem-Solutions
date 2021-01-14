n, m = map(int, input().split())
ar = list(map(int, input().split()))
ar.append(0)
ar.append(n+1)

sorted(ar)

print(ar)