n, m = map(int, input().split())

ar = sum(list(map(int, input().split())))

print( - 1 if n < ar else n - ar)