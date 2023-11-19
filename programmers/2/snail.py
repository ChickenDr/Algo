def solution(n):
    if n == 1: return [1]
    if n == 2: return [1, 2, 3]
    if n == 3: return [1, 2, 6, 3, 4, 5]
    
    answer = []
    tmap = [[0 for _ in range(n)] for _ in range(n)]
    
    loop = 0
    for i in range(1, n + 1):
        loop += i
    
    cnt = 1
    
    row = 0
    col = 0
    
    while(cnt <= loop):      
        while(True):
            if tmap[col][row] != 0: break
            
            tmap[col][row] = cnt
            cnt += 1
            if col + 1 == n: break
            if tmap[col + 1][row] != 0: break
            
            col += 1
            
        row += 1
        
        while(True):
            if tmap[col][row] != 0: break
            
            tmap[col][row] = cnt
            cnt += 1
            if row + 1 == n: break
            if tmap[col][row + 1] != 0: break
            
            row += 1

        col -= 1
        row -= 1
        
        while(True):
            if tmap[col][row] != 0: break
            
            tmap[col][row] = cnt
            cnt += 1
            
            if tmap[col - 1][row - 1] != 0: break
            
            col -= 1
            row -= 1
        
        col += 1
    
    for i in tmap:
        for x in i:
            if x ==  0:
                break
            answer.append(x)
    
    return answer

print(solution(5))