def solution(places):
    answer = []
    
    my = [1, -1, 0, 0]
    mx = [0, 0, 1, -1]
    
    def check(place):
        tmap = []
        p_locate = []
        o_locate = []
        
        for items in place:
            tmap.append(list(items))
        
        for y in range(5):
            for x in range(5):
                if tmap[y][x] == 'P': p_locate.append([y, x])
                if tmap[y][x] == 'O': o_locate.append([y, x])
        
        if len(p_locate) == 0: return 1

        for i in p_locate:
            for j in p_locate:
                if i == j: continue
                if abs(i[0] - j[0]) + abs(i[1] - j[1]) < 2: return 0
        
        if len(o_locate) == 0: return 1
        
        for o in o_locate:
            cnt = 0
            for cord in range(4):
                cy = o[0] + my[cord]
                cx = o[1] + mx[cord]
                if cy < 0 or cx < 0 or cx > 4 or cy > 4: continue
                if tmap[cy][cx] == 'P': cnt += 1
                
            if cnt >= 2: return 0
            
        return 1
    
    for place in places:
        answer.append(check(place))
    
        
    return answer

print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))