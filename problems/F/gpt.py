def solve_blocked_out(test_cases):
    results = []
    
    for n, grid in test_cases:
        # Create sets to track which blocks are already in each row and column
        row_used = [set(row.replace('.', '').replace('#', '')) for row in grid]
        col_used = [set(grid[r][c] for r in range(n) if grid[r][c] != '.' and grid[r][c] != '#') for c in range(n)]
        
        # Work through the grid and fill missing cells
        grid = [list(row) for row in grid]
        for r in range(n):
            for c in range(n):
                if grid[r][c] == '#':
                    # Determine which block to place here
                    for block in 'XY':
                        if block not in row_used[r] and block not in col_used[c]:
                            grid[r][c] = block
                            row_used[r].add(block)
                            col_used[c].add(block)
                            break
        
        # Add the completed grid to results
        results.append('\n'.join(''.join(row) for row in grid))
    
    return results

# Input parsing
import sys
input = sys.stdin.read
data = input().split()
t = int(data[0])
index = 1

test_cases = []
for _ in range(t):
    n = int(data[index])
    index += 1
    grid = data[index:index + n]
    index += n
    test_cases.append((n, grid))

# Solve and print results
results = solve_blocked_out(test_cases)
sys.stdout.write('\n'.join(results))
