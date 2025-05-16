def evaluate_with_precedence(bits, a, b):
    """
    Evaluate the bitstring using fixed precedence: ANDs first, then ORs.
    """
    # Step 1: Collapse all ANDs
    collapsed_bits = []
    i = 0
    while i < len(bits):
        if i + 1 < len(bits) and a > 0:
            # Apply AND
            collapsed_bits.append(bits[i] & bits[i + 1])
            i += 2  # Skip the next bit (already used)
            a -= 1
        else:
            # No AND applied
            collapsed_bits.append(bits[i])
            i += 1

    # Step 2: Collapse all ORs
    result = collapsed_bits[0]
    for j in range(1, len(collapsed_bits)):
        if b > 0:
            result |= collapsed_bits[j]
            b -= 1

    return result

def optimized_solution(t, test_cases):
    results = []
    
    for a, b, s in test_cases:
        bits = list(map(int, s))
        
        # Polly's optimal result
        polly_result = evaluate_with_precedence(bits, a, b)
        
        # Calvin's optimal result
        calvin_result = evaluate_with_precedence(bits, a, b)
        
        # Determine the winner
        if polly_result == 1 and calvin_result == 0:
            results.append("TIE")
        elif polly_result == 1:
            results.append("POLLY")
        else:
            results.append("CALVIN")
    
    return results

# Input reading
t = int(input())
test_cases = []
for _ in range(t):
    a, b = map(int, input().split())
    s = input().strip()
    test_cases.append((a, b, s))

# Output results
results = optimized_solution(t, test_cases)
print("\n".join(results))
