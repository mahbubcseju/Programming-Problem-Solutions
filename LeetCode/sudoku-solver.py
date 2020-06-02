class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def checkBit(musk: int, pos: int) -> bool:
            if (musk & (1<<pos)):
                return True
            return False
        
        def setBit(musk:int, pos:int) -> int:
            return (musk | (1 << pos))
        
        def unSetBit(musk:int , pos:int ) ->int:
            return (musk ^ (1<<pos))
        
        def backTrack(i:int, j:int, musk: List[List[int]], muskRowCol: List[int]) -> bool:
            if i == 9:
                return True
            
            if j == 9:
                return backTrack(i + 1, 0, musk, muskRowCol)
            
            value = board[i][j]
            if board[i][j].isnumeric():
                digit = int(value) - 1
                if backTrack(i, j + 1, musk, muskRowCol):
                        return True
                return False
            
            for digit in range(9):
                if not checkBit(muskRowCol[0][i], digit) and not checkBit(muskRowCol[1][j], digit) and not checkBit(musk[i//3][j//3], digit):
                    muskRowCol[0][i] = setBit(muskRowCol[0][i], digit)
                    muskRowCol[1][j] = setBit(muskRowCol[1][j], digit)
                    musk[i//3][j//3] = setBit(musk[i//3][j//3], digit)
                    board[i][j] = str(digit + 1)
                    if backTrack(i, j + 1, musk, muskRowCol):
                         return True
                    muskRowCol[0][i] = unSetBit(muskRowCol[0][i], digit)
                    muskRowCol[1][j] = unSetBit(muskRowCol[1][j], digit)
                    musk[i//3][j//3] = unSetBit(musk[i//3][j//3], digit)
                    
            board[i][j] = value 
            return False

        musk = [[0] *3 for i in range(3)]
        muskRowCol = [[0] * 10  for i in range(2)]
        
        for i in range(9):
            for j in range(9):
                if board[i][j].isnumeric():
                    digit = int(board[i][j]) - 1
                    muskRowCol[0][i] = setBit(muskRowCol[0][i], digit)
                    muskRowCol[1][j] = setBit(muskRowCol[1][j], digit)
                    musk[i//3][j//3] = setBit(musk[i//3][j//3], digit)
        
        backTrack(0, 0, musk, muskRowCol)
