class Solution:
    
    def isMatch(self, s: str, p: str) -> bool:
        
        def DP(i: int, j: int, dp: List[int]) -> int:
            if i == len(s) and j == len(p):
                return 1
            if j == len(p):
                return 0
   
            if dp[i][j] != -1 :
                return dp[i][j]
            
            ans = 0
            
            if p[j] == '*':
                ans |= DP(i, j + 1, dp)
                if i < len(s):
                    ans |= DP(i + 1, j, dp)
            elif i < len(s) and p[j] == '?':
                ans |= DP(i + 1, j + 1, dp)
            elif i < len(s) and s[i] == p[j]:
                ans |= DP(i + 1, j + 1, dp)
            
            dp[i][j] = ans
            
            return ans
        
        dp = [[-1] * (len(p) + 1) for i in range(len(s) + 1) ]
        return DP(0, 0, dp)
        
        