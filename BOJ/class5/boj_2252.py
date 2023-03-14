import heapq

tmp = []
resualt = []
target  = 0

def solve():
    while tmp:
        x = heapq.heappop(tmp)
        resualt.append(x)
        
        for nx in graph[x]:
            degree[nx] -= 1

            if degree[nx] == 0:
                heapq.heappush(tmp, nx)
    return resualt

if __name__ == "__main__":
    n, k = map(int, input().split())

    graph = [[] for _ in range(n + 1)]
    degree = [0] * (n + 1)
        
    for _ in range(k):
        a, b = map(int, input().split())
        graph[a].append(b)
        degree[b] += 1
    
        
    for i in range(1, n + 1):
        if degree[i] == 0:
            heapq.heappush(tmp, i)
    solve()
    print(*resualt)