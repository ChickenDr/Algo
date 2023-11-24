def solution(s):
    answer = ''
    tmp = list(s.split(' '))
    
    for g_index, g in enumerate(tmp):
        for x_index, x in enumerate(g):
            if x_index % 2 == 1:
                answer += x.lower()
            else:
                answer += x.upper()
        
        if g_index != len(tmp):
            answer += ' '
            
    return answer
    
print(solution("try hello world"))