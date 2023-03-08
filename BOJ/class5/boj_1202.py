
import sys
import heapq


arr = []
bag = []

def solve():
    resualt = 0
    tmp = []
    for x in bag:
        while arr and x >= arr[0][0]:
            heapq.heappush(tmp, -heapq.heappop(arr)[1])
        if tmp:
            resualt -= heapq.heappop(tmp)
        elif not arr:
            break
    return resualt

if __name__ == "__main__":
    N, K = map(int, input().split())
    
    for _ in range(N):
        heapq.heappush(arr, list(map(int, sys.stdin.readline().split())))
    
    for _ in range(K):
        bag.append(int(sys.stdin.readline()))
    
    bag.sort()

    print(f"{solve()}")