import sys
from collections import deque

n, m = map(int, input().split())

room = []

room = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(n)]

resualt = [[0] * m for _ in range(n)]
visit = [[0] * m for _ in range(n)]

mx = [-1, 1, 0, 0]
my = [0, 0, 1, -1]

cnt = 2

dic = {}


def bfs(y, x, c):
    q = deque()
    q.append((y, x))
    go = 1

    while q:
        curr = q.popleft()
        room[curr[0]][curr[1]] = c

        for i in range(4):
            nx = curr[1] + mx[i]
            ny = curr[0] + my[i]

            if nx < 0 or ny < 0 or nx >= m or ny >= n:
                continue

            if visit[ny][nx]:
                continue

            if not room[ny][nx]:
                go += 1
                visit[ny][nx] = 1
                q.append((ny, nx))
    return go


for y in range(n):
    for x in range(m):
        if not room[y][x] and not visit[y][x]:
            dic[cnt] = bfs(y, x, cnt)
            cnt += 1

for y in range(n):
    for x in range(m):
        if room[y][x] == 1:
            data = set()
            tmp = 1
            for i in range(4):
                nx = x + mx[i]
                ny = y + my[i]

                if nx < 0 or ny < 0 or nx >= m or ny >= n:
                    continue
                if room[ny][nx] == 1:
                    continue

                data.add(room[ny][nx])

            for i in data:
                tmp += dic[i]

            resualt[y][x] = tmp % 10


for i in range(n):
    print("".join(map(str, resualt[i])))
