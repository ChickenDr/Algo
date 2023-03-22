import sys
resualt = 0

r, c, m = map(int, input().split())
room = [[0 for _ in range(c + 1)] for _ in range(r + 1)]

for _ in range(m):
    a, b, g, d, e = map(int, sys.stdin.readline().split())
    room[a][b] = [a, b, g, d, e]

for time in range(1, c + 1):
    new_room = [[0 for _ in range(c + 1)] for _ in range(r + 1)]

    for s in range(1, r + 1):
        if room[s][time]:
            resualt += room[s][time][4]
            room[s][time] = 0
            break

    for y in range(1, r + 1):
        for x in range(1, c + 1):
            shark = room[y][x]
            if shark:
                speed = shark[2]

                if shark[3] == 1 or shark[3] == 2:
                    speed %= ((2 * r) - 2)
                elif shark[3] == 3 or shark[3] == 4:
                    speed %= ((2 * c) - 2)

                while speed:
                    if shark[3] == 1:
                        if shark[0] == 1:
                            shark[3] += 1
                            continue
                        else:
                            shark[0] -= 1

                    elif shark[3] == 2:
                        if shark[0] == r:
                            shark[3] -= 1
                            continue
                        else:
                            shark[0] += 1

                    elif shark[3] == 3:
                        if shark[1] == c:
                            shark[3] += 1
                            continue
                        else:
                            shark[1] += 1

                    elif shark[3] == 4:
                        if shark[1] == 1:
                            shark[3] -= 1
                            continue
                        else:
                            shark[1] -= 1
                    speed -= 1

                if not new_room[shark[0]][shark[1]] or new_room[shark[0]][shark[1]][4] < shark[4]:
                    new_room[shark[0]][shark[1]] = shark
    room = new_room

print(resualt)
