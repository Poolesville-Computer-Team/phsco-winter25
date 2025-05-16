def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    t = int(data[0])
    results = []

    for i in range(1, t + 1):
        n = int(data[i])
        max_score = 0
        max_count = 0
        radius = int(n**0.5)
        score_count = {}

        for x in range(radius + 1):
            for y in range(radius + 1):
                if x**2 + y**2 <= n:
                    score = min(x, y)
                    if score in score_count:
                        score_count[score] += 1
                    else:
                        score_count[score] = 1

        max_score = max(score_count.keys())
        max_count = score_count[max_score]

        # Symmetry considerations
        total_count = max_count * 4
        if radius**2 <= n:  # Count points on axes exactly once
            total_count -= 4 * max_score
            total_count += 1  # Add (0,0) if applicable

        results.append(f"{max_score} {total_count}")

    sys.stdout.write("\n".join(results) + "\n")


solve()