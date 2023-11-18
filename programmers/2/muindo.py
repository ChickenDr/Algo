global false_array
global col
global row
global gmap
mx = [1, -1, 0, 0]
my = [0, 0, 1, -1]

false_array = []

def solve(x, y):
    global false_array, row, col, gmap
    
    q = [(x, y)]
    false_array[x][y] = True
    
    total = int(gmap[x][y])

    while q:
        cx, cy = q.pop(0)
        
        for i in range(4):
            tx = cx + mx[i]
            ty = cy + my[i]
            
            if tx < 0 or tx >= row or ty < 0 or ty >= col:
                continue
            
            if gmap[tx][ty] != 'X' and not false_array[tx][ty]:
                false_array[tx][ty] = True
                q.append((tx, ty))
                total += int(gmap[tx][ty])
    
    return total

    

def solution(maps):
    global false_array, row, col, gmap
    check = True
    
    gmap = maps
    col = len(maps[0])
    row = len(maps)
    
    answer = []
    
    false_array = [[False for _ in range(col)] for _ in range(row)]
    
    
    for row_index, map_row in enumerate(maps):
        row_item = list(map_row)

        for col_index, col_item in enumerate(row_item):
            if col_item != 'X' and not false_array[row_index][col_index]:
                false_array[row_index][col_index] = True
                check = False
                answer.append(solve(row_index, col_index))
                
    if check: return [-1]
    
    answer.sort()

    return answer


solution(["X591X","X1X5X","X231X", "1XXX1"])