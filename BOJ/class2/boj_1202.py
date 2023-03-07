

global loop, bag
arr = []
bagW = []

def solve():
    return

if __name__ == "__main__":
    loop, bag = map(int, input().split())
    
    while(loop):
        arr.append(list(map(int, input().split())))
        loop -= 1
    
    while(bag):
        bagW.append(int(input()))
        bag -= 1

    arr.sort(key = lambda x:-x[1])
    bagW.sort()

    print(arr)