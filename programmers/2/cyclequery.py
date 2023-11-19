def solution(rows, columns, queries):
    answer = []
    tmap = [[columns * r + c + 1 for c in range(columns)] for r in range(rows)]
    
    min_x = 0
    min_y = 0
    
    def cycle(sy, sx, ey, ex, d, pre, min):
        tmp = tmap[sy][sx]
        tmap[sy][sx] = pre
        
        if min > pre:
            min = pre
        
        if d == 1:
            if ex < sx + 1:
                return cycle(sy + 1, sx, ey, ex, 2, tmp, min)
            else:
                return cycle(sy, sx + 1, ey, ex, 1, tmp, min)
        elif d == 2:
            if ey < sy + 1:
                return cycle(sy, sx - 1, ey, ex, 3, tmp, min)
            else:
                return cycle(sy + 1, sx, ey, ex, 2, tmp, min)
        elif d == 3:
            if min_x > sx - 1:
                return cycle(sy - 1, sx, ey, ex, 4, tmp, min)
            else:
                return cycle(sy, sx - 1, ey, ex, 3, tmp, min)
        elif d == 4:
            if min_y > sy - 1:
                return min
            else:
                return cycle(sy - 1, sx, ey, ex, 4, tmp, min)
         
 
    for sy, sx, ey, ex in queries:
        min_y = sy - 1
        min_x = sx - 1
        answer.append(cycle(sy - 1, sx - 1, ey - 1, ex - 1, 1, tmap[min_y][min_x], int(1e15)))
        
    return answer

print(solution(6, 6, [[2,2,5,4],[3,3,6,6],[5,1,6,3]]))