t = int(input())

for test in range(t):
    s = input()
    val_map = dict()

    res = 0
    max_val = 15

    for i in range(len(s)):
        ch = s[i]
        place = len(s) - 1 - i

        if val_map.get(ch, 0) == 0:
            val_map[ch] = max_val
            max_val -= 1
        
        res += val_map[ch] * 16**place
    
    print(res)