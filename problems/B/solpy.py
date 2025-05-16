n, s = map(int, input().split())

pts = 0
tot = 0
for _ in range(n):
    a, b = map(int, input().split())
    pts += a
    tot += b

pts += s
tot += s

if pts * 10 >= tot * 9:
    print("YES")
else:
    print("NO")