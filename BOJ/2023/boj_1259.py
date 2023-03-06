import sys
arr = list(map(int, sys.stdin.readline().split()))


def solve():
    resualt = True
    for i in range(0, arr.count):
        for j in range(arr.count, -1):
            if (i == j):
                break
            if (arr[i] != arr[j]):
                resualt = False
                break
    return resualt


if __name__ == __s:
    s
