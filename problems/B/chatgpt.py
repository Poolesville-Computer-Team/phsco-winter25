import math

# Read the number of assignments and final exam points
n, s = map(int, input().split())

# Initialize current points and total max points
current_points = 0
total_max = s

# Process each assignment
for _ in range(n):
    a, b = map(int, input().split())
    current_points += a
    total_max += b

# Calculate the minimum points required to get an A
required_points = math.ceil(0.9 * total_max)

# Check if Polly can achieve the required points
if current_points + s >= required_points:
    print("YES")
else:
    print("NO")
