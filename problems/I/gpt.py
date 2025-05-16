def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    t = int(data[index])
    index += 1
    
    results = []
    
    for _ in range(t):
        n, q = map(int, data[index:index + 2])
        index += 2
        dice_faces = list(map(int, data[index:index + n]))
        index += n
        queries = list(map(int, data[index:index + q]))
        index += q
        
        # Sort dice faces in descending order
        dice_faces.sort(reverse=True)
        
        for s in queries:
            remaining = s
            rolls = 0
            used = [False] * n  # Track used dice
            
            for i, face in enumerate(dice_faces):
                if remaining <= 0:
                    break
                if not used[i] and remaining >= face:
                    # Use this die
                    used[i] = True
                    remaining -= face
                    rolls += 1
            
            if remaining > 0:
                results.append(-1)
            else:
                results.append(rolls)
    
    sys.stdout.write("\n".join(map(str, results)) + "\n")
