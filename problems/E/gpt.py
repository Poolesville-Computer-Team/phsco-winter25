def max_cursed_hexadecimal(t, test_cases):
    results = []
    
    for s in test_cases:
        # Frequency of each character
        freq = {}
        for i, c in enumerate(s):
            if c not in freq:
                freq[c] = 0
            # Higher position => higher weight
            freq[c] += 16 ** (len(s) - i - 1)
        
        # Sort by frequency (descending)
        sorted_chars = sorted(freq.items(), key=lambda x: -x[1])
        
        # Assign the highest values to the most significant characters
        mapping = {}
        value = 15
        for char, _ in sorted_chars:
            mapping[char] = value
            value -= 1
        
        # Calculate the decimal value
        decimal_value = 0
        for i, c in enumerate(s):
            decimal_value += mapping[c] * (16 ** (len(s) - i - 1))
        
        results.append(decimal_value)
    
    return results

# Input Handling
t = int(input())
test_cases = [input().strip() for _ in range(t)]
results = max_cursed_hexadecimal(t, test_cases)

# Output Results
for res in results:
    print(res)
