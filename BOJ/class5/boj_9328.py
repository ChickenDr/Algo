import sys

room = []
visit = []


def solve(w, h):
    global visit, room

    door = []
    key = []
    resualt = 0
    q = []
    visit[0][0] = 1
    mx = [1, -1, 0, 0]
    my = [0, 0, -1, 1]
    
    q.append([0, 0])
   
    while q:
        curr = q.pop(0)
        for i in range(0, 4):
            cx = curr[1] + mx[i]
            cy = curr[0] + my[i]

            if cy < 0 or cx < 0 or cx > w + 1 or  cy > h + 1 or visit[cy][cx] == 1 or room[cy][cx] == '*':
                continue

    
    key.clear()
    door.clear()
    visit.clear()
    room.clear()
    
    return resualt

if __name__ == "__main__":
    
    loop = int(input())

    for _ in range(loop):
        h, w  = map(int, input().split())
        
        visit = [[0] * (w + 2)]
        for _ in range(h + 1):
            visit.append([0] * (w + 2))

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