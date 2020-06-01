class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        
        dp = [[0] * len(grid[i]) for i in range(len(grid))]
        
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if i == 0 and j == 0:
                    dp[i][j] = grid[i][j]
                else:
                    dp[i][j] = grid[i][j] + min(dp[i-1][j]  if i else dp[i][j-1], dp[i][j-1] if j else dp[i-1][j])
                    
                    
        return dp[len(grid) - 1][len(grid[0]) - 1]