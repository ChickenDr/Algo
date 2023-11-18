def solution(board, moves):
    answer = 0
    tmp = []

    col = len(board[0])
    
    board_stack = [[] for _ in range(col)]
    print(board_stack)
    
    for board_index, board_row in enumerate(board):
        for col_index, board_col in enumerate(board_row):
            if(board[board_index][col_index] != 0):
                board_stack[col_index].append(board_col)
    
    for move in moves:
        if(len(board_stack[move - 1]) == 0):
            continue
        
        item = board_stack[move - 1].pop(0)
        tmp.append(item)
        
        if(len(tmp) >= 2 and tmp[-2] == tmp[-1]):
            answer += 2
            tmp.pop(-1)
            tmp.pop(-1)
            
    return answer
