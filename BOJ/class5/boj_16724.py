
n, m = map(int, input().split())

room = []
resualt = 0
visit = [[False for _ in m] for _ in m]


def solve(y, x):
    if visit[y][x] or x >= m or y >= m or x < 0 or y < 0:
        return

    visit[y][x] == True

    if room[y][x] == 'R':
        solve(y, x + 1)
    elif room[y][x] == 'L':
        solve(y, x - 1)
    elif room[y][x] == 'D':
        solve(y - 1, x)
    elif room[y][x] == 'U':
        solve(y + 1, x)


for _ in n:
    room.append(input().split())
