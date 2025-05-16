a = int(input())
b = int(input())
c = int(input())
d = int(input())

max_k = -1

# We need to find the minimal h such that (h + s)*b >=c, then compute for h up to that
# But iterate up to a reasonable h_max. Let's set h_max to c//b + 3*3 to cover all possibilities
h_max = (c // b) + 10  # Adding 10 for safety, adjust if needed
h_max = max(h_max, 100)  # Ensure we cover enough cases

for h in range(0, 2 * h_max):
    s = h // 3
    total_damage_stanley = (h + s) * b
    if total_damage_stanley < c:
        continue  # Not enough damage to defeat Stanley
    
    # Simulate the h hits to find s_count (number of times Stanley survived and attacked)
    stanley_hp = c
    polly_meter = 0
    s_count = 0
    for _ in range(h):
        # Process the hit
        stanley_hp -= b
        
        # Check if Stanley is dead after the hit but before the super attack
        # Regardless, proceed to check super attack
        polly_meter += 1
        
        # Check if super attack is triggered
        if polly_meter == 3:
            stanley_hp -= b
            polly_meter = 0  # Reset meter after super attack
        
        # Check if Stanley is alive after all hits and super attacks
        if stanley_hp > 0:
            s_count += 1
        else:
            # Once Stanley is dead, no more attacks from him
            # Break the loop as further hits are not needed
            break
    
    # Calculate the maximum possible k
    # Total damage to Polly: k*d + s_count*d < a
    # k*d < a - s_count*d
    # k_max = (a - 1 - s_count * d) // d
    if d == 0:
        # Stanley deals no damage, Polly can miss all attacks
        current_max_k = 10**18  # Very large number
    else:
        numerator = (a - 1) - s_count * d
        if numerator < 0:
            continue  # Even 0 misses are not possible
        current_max_k = numerator // d
    
    # Also, after k misses, Polly's health before processing hits must be positive
    # a - k*d > 0 => k < a / d
    if d != 0:
        max_possible_k_before_death = (a - 1) // d
        current_max_k = min(current_max_k, max_possible_k_before_death)
    
    if current_max_k < 0:
        continue
    
    # Check if the total damage to Polly is strictly less than a
    if current_max_k * d + s_count * d >= a:
        continue
    
    # Update max_k
    if current_max_k > max_k:
        max_k = current_max_k

if max_k >= 0:
    print(max_k)
else:
    print(-1)