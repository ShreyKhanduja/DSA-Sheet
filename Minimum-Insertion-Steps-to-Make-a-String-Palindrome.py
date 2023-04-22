class Solution:
    def minInsertions(self, s: str) -> int:
        # find longest common sequence for s and reversed(s)
        n = len(s)
        dp = [[0]*(n+1) for i in range(n+1)]
        
        for i in range(n):
            for j in range(n):
                dp[i+1][j+1] = dp[i][j] + 1 if s[i] == s[~j] else max(dp[i+1][j], dp[i][j+1])
        return n - dp[n][n]
