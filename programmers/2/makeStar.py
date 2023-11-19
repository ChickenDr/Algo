def solution(line):
    cross = []
    answer = []
    min_x =  min_y = int(1e15);
    max_x = max_y = -int(1e15);
    
    n = len(line)
    
    for x in range(n):
        a, b, e = line[x]
        for i in range(x + 1, n):
            c, d, f = line[i]
            
            if a * d == b * c:
                continue
            
            c_x = (b * f - e * d) / (a * d - b * c)
            c_y = (e * c - a * f) / (a * d - b * c)
            
            if c_x == int(c_x) and c_y == int(c_y):
                ix = int(c_x)
                iy = int(c_y)
                
                cross.append([ix, iy])
                
                if min_x > ix: min_x = ix
                if max_x < ix: max_x = ix
                if min_y > iy: min_y = iy
                if max_y < iy: max_y = iy  
    
    tmp = [['.'] * (max_x - min_x + 1) for _ in range((max_y - min_y + 1))]
    
    
    for px, py in cross:
        my = 0
        mx = 0
        if min_y < 0:
            my = py + abs(min_y)
        else:
            my = py - min_y

        if min_x < 0:
            mx = px + abs(min_x)
        else:
            mx = px - min_x
        
        tmp[my][mx] = '*'
        
    
    for x in tmp:
        answer.append(''.join(x))
        
    return answer[::-1]

print(solution([[2, -1, 4], [-2, -1, 4], [0, -1, 1], [5, -8, -12], [5, 8, 12]]))