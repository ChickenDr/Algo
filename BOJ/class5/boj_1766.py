import sys
import heapq

global graph, degree
resualt = []
arr = []

def solve():
    while arr:
        x = heapq.heappop(arr)
        resualt.append(x)

        for nx in graph[x]:
            degree[nx] -= 1

            if degree[nx] == 0:
                heapq.heappush(arr, nx)
    return


if __name__ == "__main__":
    N, M = map(int, input().split())

    graph = [[] for _ in range(N + 1)]
    degree = [0] * (N + 1)
    
    for _ in range(M):
        a, b = map(int, input().split())
        graph[a].append(b)
        degree[b] += 1
    
    for i in range(1, N + 1):
        if degree[i] == 0:
            heapq.heappush(arr, i)

    solve()
    print(*resualt)