arr = []
resualt = []

def solve():
    arr.sort(key = lambda x:(x[0], x[1]))

    return

if __name__ == "__main__":
    loop = int(input())
    while(loop):
        arr.append(list(map(int, input().split())))
        loop -=1
    
    solve()

    for x in arr:
        print(f"{x[0]} {x[1]}")