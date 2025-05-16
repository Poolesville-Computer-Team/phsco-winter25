import math

def f(x, y):
    if x < 0:
        return f(-1 * x, y)
    if y < 0:
        return f(x, -1 * y)
    if x > y:
        return f(x - 1, y)
    if y > x:
        return f(x, y - 1)
    if x != 0:
        return 1 + f(x - 1, y - 1)
    return 0

def main():
    import sys
    input = sys.stdin.read().split()
    t = int(input[0])
    idx = 1
    for _ in range(t):
        n = int(input[idx])
        idx += 1
        r = int(math.isqrt(n))
        max_s = 0
        count = 0
        for x in range(-r, r + 1):
            for y in range(-r, r + 1):
                if x**2 + y**2 <= n:
                    s = f(x, y)
                    if s > max_s:
                        max_s = s
                        count = 1
                    elif s == max_s:
                        count += 1
        print(max_s, count)

if __name__ == "__main__":
    main()