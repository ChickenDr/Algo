import math
import sys

resualt = 0
visit = []

def is_prime_num(n):
    arr = [True] * (n + 1)
    tmp = []
    arr[0] = False
    arr[1] = False

    for i in range(2, int(math.sqrt(n)+1)):
        if arr[i] == True:
            j = 2

            while (i * j) <= n:
                arr[i*j] = False
                j += 1

    for i in range(4000000):
        if arr[i]:
            tmp.append(i)
        
    return tmp

def dfs(x, deep):
    global target, data, resualt

    visit[deep] = 1
    
    if x == target: 
        return 1

    if x + data[deep] > target: 
        return 0
    
    
    
    return  dfs(x + data[deep], deep + 1) +  dfs(x, deep + 1)
     

if __name__ == '__main__':
    sys.setrecursionlimit(10**7)
    data = is_prime_num(4000000)

    visit = [0 for _ in data]
    target = int(input())

    print(f'{dfs(0, 0)}')