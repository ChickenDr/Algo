def solution(s):
    if len(s) % 2 == 1: return 0
    
    answer = 0
    
    tmp = list(s)
    tmap = []
    
    for x in tmp:
        if len(tmap) == 0:
            tmap.append(x)
            continue
        
        if tmap[-1] == x:
            tmap.pop()
        else:
            tmap.append(x)
            
    if len(tmap) == 0:
        answer = 1
    
    return answer

print(solution("baabaa"))