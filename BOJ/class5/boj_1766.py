import sys
import heapq

arr = []
resualt = []

def solve():
    while arr:
        tmp = heapq.heappop(arr)
        if tmp[0] in resualt:
            continue
        resualt.append(tmp[0])
        resualt.append(tmp[1])
    return


if __name__ == "__main__":
    N, M = map(int, input().split())

    for _ in range(M):
        heapq.heappush(arr, list(map(int, sys.stdin.readline().split())))

    print(arr)
    solve()
    for x in resualt:
        print(f'{x}', end=" ")