def solution(s):
    answer = {}
    
    d = s[2:-2].split("},{")
    d = sorted(d, key = len)
    
    for item in d:
        item = item.split(',')
        for v in item:
            if int(v) not in answer:
                answer[int(v)] = 1
    
    return list(answer)

print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))