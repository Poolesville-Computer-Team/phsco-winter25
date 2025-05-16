def max_misses_to_win(a, b, c, d):
    def can_win_with_misses(misses):
        polly_health = a
        calvin_health = c
        polly_super_meter = 0
        turn = 0
        
        while polly_health > 0 and calvin_health > 0:
            if turn % 2 == 0:  # Polly's turn
                if misses > 0:
                    # Polly intentionally misses
                    misses -= 1
                elif polly_super_meter == 3:
                    # Supercharged attack
                    calvin_health -= b
                    polly_super_meter = 0
                else:
                    # Normal attack
                    calvin_health -= b
                    polly_super_meter += 1
            else:  # Calvin's turn
                polly_health -= d
            turn += 1
        
        return calvin_health <= 0 and polly_health > 0

    # Binary search for the maximum number of misses Polly can afford
    left, right, result = 0, 10**9, -1
    while left <= right:
        mid = (left + right) // 2
        if can_win_with_misses(mid):
            result = mid
            left = mid + 1
        else:
            right = mid - 1
    
    return result

# Input
a = int(input())
b = int(input())
c = int(input())
d = int(input())

# Output
print(max_misses_to_win(a, b, c, d))
