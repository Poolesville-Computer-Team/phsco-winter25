n, s = map(int, input().split())

pts = 0
tot = 0
for _ in range(n):
    a, b = map(int, input().split())
    pts += a
    tot += b

tot += s

worked = False
for i in range(0, s+1):
    if (pts + i) * 10 >= tot * 9:
        print("YES")
        worked = True
        break

if not worked:
    print("NO")