t = int(input())

for i in range(t):
    inp = list(map(int, input().split()))
    a = inp[0]
    b = inp[1]
    s = input().strip()
    slen = len(s)

    numzeros = 0
    numones = 0
    for ch in s:
        if ch == "0":
            numzeros += 1
        else:
            numones += 1
    

    polly = False
    if b >= 2:
        polly = (numones > 0)
    elif b == 1:
        polly = (s[0] == "1" or s[-1] == "1")
    else:
        polly = (numzeros == 0)
    
    calvin = False
    if numones == 0:
        calvin = True
    elif numzeros == 0:
        calvin = False
    else:
        lastPartitionHasZero = False
        for i in range(0, slen-1):
            ch = s[i]
            if (ch == "0"):
                if b > 0:
                    b -= 1
                elif not lastPartitionHasZero:
                    lastPartitionHasZero = True
    
        if b == 0 and s[-1] == "0" and not lastPartitionHasZero:
            lastPartitionHasZero = True
        
        calvin = (b == 0 and lastPartitionHasZero)
    
    if polly and calvin:
        print("TIE")
    elif polly:
        print("POLLY")
    else:
        print("CALVIN")