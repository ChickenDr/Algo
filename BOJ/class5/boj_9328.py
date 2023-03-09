import sys

room = []
visit = []
key = []
mx = [1, -1, 0, 0]
my = [0, 0, -1, 1]

def solve(x, y):
    q = []
    q.append([x, y])
    return

if __name__ == "__main__":
    loop = int(input())
    for _ in range(loop):
        h, w  = map(int, input().split())
        
        visit = [[0] * (w + 1)] * (h + 1)
        print(visit)
        visit.insert(0, [0 * (w)])
        

        for i in range(h):
            visit[i].insert(0, 0)
            visit[i].append(0, 0)

        for _ in range(h):
            room.append(list(input()))
        
        key = list(input().split())

        print(room)
        print(key)

