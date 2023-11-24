def solution(s, n):
    answer = ''
    tmp = list(s)
    
    for x in tmp:
        if x == ' ': 
            answer += ' '
        corr = ord('A') if x.isupper() else ord('a')
        answer += chr((ord(x) - corr + n) % 26 + corr)
        
        
    return answer
    

print(solution("ABCCSDSDFAGSGZWWQR", 24))