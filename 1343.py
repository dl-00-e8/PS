board = list(map(str, input()))

cnt = 0
for i in range(len(board)):
    if board[i] == 'X':
        cnt += 1
        if cnt % 4 == 0:
            board[i - 3] = 'A'
            board[i - 2] = 'A'
            board[i - 1] = 'A'
            board[i] = 'A'
            cnt = 0
        elif cnt % 2 == 0:
            if i == len(board) - 1 or board[i + 1] != 'X':
                board[i - 1] = 'B'
                board[i] = 'B'
                cnt = 0
            elif board[i + 1] == 'X':
                continue   
    elif board[i] == '.':
        cnt = 0 # cnt 0 초기화

if board.count('X') >= 1:
    print(-1)
else:
    for i in board:
        print(i, end = "")
