import sys

inf = 1e18
table = []
cycle = False


def solve(n):
    global cycle

    for node in range(n):
        for i in range(n):
            for x in d[i]:
                nextNode = x[0]
                weight = x[1]
                if (table[i] != inf and table[nextNode] > table[i] + weight):
                    table[nextNode] = table[i] + weight
                    if node == n - 1:
                        cycle = True
    return


if __name__ == '__main__':
    n, m = map(int, input().split())

    for _ in range(n):
        d = [[] for _ in range(n)]

    for _ in range(m):
        a, b, c = map(int, input().split())
        d[a - 1].append([b - 1, c])

    table = [inf for _ in range(500)]
    table[0] = 0

    solve(n)

    if cycle:
        print(-1)
    else:
        for i in range(1, n):
            if table[i] == inf:
                print(-1)
            else:
                print(table[i])
