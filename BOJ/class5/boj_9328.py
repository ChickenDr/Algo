import sys

room = []
visit = []
mx = [1, -1, 0, 0]
my = [0, 0, -1, 1]

def solve():
    return

if __name__ == "__main__":
    loop = int(input())

    for _ in range(loop):
        h, w  = map(int, input().split())
        visit = [[False * w] * h]

        for _ in range(h):
            room.append(list(map(int, sys.stdin.readline().split())))
        

        