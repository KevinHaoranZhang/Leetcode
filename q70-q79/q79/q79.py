class Solution:
    def exist(self,board, word):
        row = len(board)
        col = len(board[0])
        wlen = len(word)
        i, j = 0, 0
        def find(i, j,index):
            if index >= wlen:
                return True
            temp=board[i][j]
            board[i][j]=None
            if i + 1 < row and j < col:
                if board[i + 1][j] == word[index]:
                    if find(i + 1, j,index + 1):
                        return True
            if i - 1 >= 0 and j < col:
                if board[i - 1][j] == word[index]:
                    if find(i - 1, j,  index + 1):
                        return True
            if i < row and j + 1 < col:
                if board[i][j + 1] == word[index]:
                    if find(i, j + 1,index + 1):
                        return True
            if i < row and j - 1 >= 0:
                if board[i][j - 1] == word[index]:
                    if find(i, j - 1,index + 1):
                        return True
            board[i][j]=temp
            return False


        for i in range(row):
            for j in range(col):
                if str(board[i][j]) == word[0]:
                    if find(i,j,1):
                        return True

        return False
