import sys

room = []
visit = []
key = []

def solve(w, h):

    visit = [[0] * (w + 2)  for _ in range(h + 2)]

    door = []
    resualt = 0
    q = []
    visit[0][0] = 1
    mx = [1, -1, 0, 0]
    my = [0, 0, -1, 1]
    
    q.append([0, 0])
    
    for k in key:
        for y in range(h + 2):
            for x in range(w + 2):
                if ord(room[y][x]) + 32 == ord(k):
                    room[y][x] = '.'
                    
    key.clear()

    while q:
        curr = q.pop(0)
        for i in range(0, 4):
            cx = curr[1] + mx[i]
            cy = curr[0] + my[i]

            if cy < 0 or cx < 0 or cx > w + 1 or  cy > h + 1 or visit[cy][cx] == 1 or room[cy][cx] == '*':
                continue
            
            tmp = ord(room[cy][cx])

            if tmp >= ord('A') and tmp <= ord('Z'):
                if [cy, cx, tmp] not in door:
                    door.append([cy, cx, tmp])
                    continue

            if tmp >= ord('a') and tmp <= ord('z'):
                room[cy][cx] = '.'
                for y in range(h + 2):
                    for x in range(w + 2):
                        if ord(room[y][x]) + 32 == tmp:
                            room[y][x] = '.'
                
                visit[cy][cx] = 1
                q.append([cy, cx])
                
                for x in door:
                    if x[2] + 32 == tmp:
                        q.append([x[0], x[1]])

            elif tmp == ord('$'):
                room[cy][cx] = '.'
                resualt += 1
                visit[cy][cx] = 1
                q.append([cy, cx])
            
            else:
                visit[cy][cx] = 1
                q.append([cy, cx])
                
    door.clear()
    visit.clear()
    room.clear()
    
    return resualt

if __name__ == "__main__":

    loop = int(input())

    for _ in range(loop):
        h, w  = map(int, input().split())

        for _ in range(h):
            room.append(list(input()))
        
        for i in range(h):
            room[i].insert(0, '.')
            room[i].append('.')
        room.insert(0, ['.'] * (w + 2))
        room.append(['.'] * (w + 2))


        tmp = input()
        if tmp != '0':
            key = list(tmp)

        print(f'{solve(w, h)}')