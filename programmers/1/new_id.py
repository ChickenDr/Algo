def solution(new_id):
    answer = ''
    new_id = new_id.lower()
    
    tmp = []
    for i in list(new_id):
        if i.isalpha() or '_' or '-' or '.':
            tmp.append(i)
            
    answer = ''.join(tmp)
    
    while '..' in answer:
        answer = answer.replace('..', '.')
    
    answer = answer.strip('.')
    
    if answer == '': answer += 'a'
    
    if len(answer) >
    
    return answer
    
print(solution("...!@BaT#*..y.abcdefghijklm"))