def solution(s):
    answer = []
    cnt = 0
    zero = 0
    while(s != '1'):
        cnt += 1
        num = s.count('1')
        zero += len(s) - num
        s = str(bin(num))[2:]
    
    return [cnt, zero]

print(solution("110010101001"))