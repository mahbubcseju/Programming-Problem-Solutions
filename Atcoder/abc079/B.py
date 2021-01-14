n = int(input())
fi, sc = 2, 1

for i in range(2, n + 1):
    fi, sc = sc, fi + sc


print(sc)