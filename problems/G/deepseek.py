import math

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    t = int(data[0])
    results = []
    
    for i in range(1, t + 1):
        n = int(data[i])
        two_n = 2 * n
        s_candidate = math.isqrt(two_n)
        even = (s_candidate % 2 == 0)
        
        if even:
            minimal = (s_candidate ** 2) // 2
            s_max = s_candidate if minimal <= n else s_candidate - 1
        else:
            minimal = (s_candidate ** 2 + 1) // 2
            s_max = s_candidate if minimal <= n else s_candidate - 1
        
        delta = two_n - s_max * s_max
        sqrt_delta = math.isqrt(delta)
        a_min = (s_max - sqrt_delta) // 2
        a_max = (s_max + sqrt_delta) // 2
        
        a_min = max(0, a_min)
        a_max = min(s_max, a_max)
        a_count = a_max - a_min + 1
        
        count_2 = 0
        if a_min <= 0 <= a_max:
            count_2 += 1
        if a_min <= s_max <= a_max:
            count_2 += 1
        
        count_4 = a_count - count_2
        total_points = count_2 * 2 + count_4 * 4
        results.append(f"{s_max} {total_points}")
    
    print('\n'.join(results))

if __name__ == "__main__":
    main()