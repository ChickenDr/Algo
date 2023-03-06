import sys

def solve(arr):
    resualt = True
    j = len(arr) - 1
    for i in range(0, len(arr)):
        if (i == j):
            break
        if (arr[i] != arr[j]):
            resualt = False
            break
        j -= 1

    if(resualt): return "yes"
    else: return "no"


if __name__ == "__main__":
    while True:
        arr = str(input())
        if(arr == "0"): 
            break
        print(f"{solve(arr)}")
    