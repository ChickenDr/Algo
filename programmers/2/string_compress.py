def solution(s):
    answer = len(s)
    
    for length in range(1, len(s) // 2 + 1):
        for rang in range(len(s) / 2):
            tmap = [[s[rang: range]]]
            
        
    
    return answer

print(solution("aabbaccc"))