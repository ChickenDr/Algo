def solution(n):
    if n == 0: return 0
    nums = []
    
    while n:
        n, digit = divmod(n, 3)
        nums.append(str(digit))
    
    
    return int(''.join(reversed(nums))[::-1], 3)

print(solution(45))