import sys
import heapq

global graph, degree
resualt = 0
arr = []
t = []

def solve():
    while arr:
        x = heapq.heappop(arr)

        m = 0

        # for i in x:
        #     if target == i:
        #         m = t[i - 1]
        #         break

        #     if arr[x - 1] > m:
        #         m = t[x - 1]
        
        # resualt += m

        for nx in graph[x]:
            degree[nx] -= 1

            if degree[nx] == 0:
                heapq.heappush(arr, nx)
    return resualt


if __name__ == "__main__":
    loop = int(input())

    for _ in range(loop):
        N, M = map(int, input().split())

        t = list(map(int, input().split()))

        graph = [[] for _ in range(N + 1)]
        degree = [0] * (N + 1)
        
        for _ in range(M):
            a, b = map(int, input().split())
            graph[a].append(b)
            degree[b] += 1
        
        for i in range(1, N + 1):
            if degree[i] == 0:
                heapq.heappush(arr, i)
        
        target = int(input())

        print(f'{solve()}')