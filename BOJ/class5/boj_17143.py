import sys


resualt = 0

shark = []

r, c, m = map(int, input().split())

room = [[] for _ in range(c)] * r

for _ in range(m):
    shark.append(list(map(int, input().split())))

for time in range(m):
    tmp = shark
    for s in shark:
        if (s[0] == time):
            resualt += s[4]
            shark.remove(tmp)

    for s in shark:
        if s[3] == 1 or s[3] == 2:
            continue
        elif s[3] == 1 or s[3] == 2:
            continue
