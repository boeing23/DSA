class Solution:
    def maxPathScore(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])

        def getcost(x):
            return 0 if x == 0 else 1

        start_cost = getcost(grid[0][0])
        if start_cost > k:
            return -1

        # dp[r][c][cost] = max score reaching (r, c) with exactly this cost
        dp = [[[-1] * (k + 1) for _ in range(n)] for _ in range(m)]

        dp[0][0][start_cost] = grid[0][0]

        for r in range(m):
            for c in range(n):
                for cost in range(k + 1):
                    if dp[r][c][cost] == -1:
                        continue

                    for dr, dc in [(1, 0), (0, 1)]:
                        nr = r + dr
                        nc = c + dc

                        if nr < m and nc < n:
                            new_cost = cost + getcost(grid[nr][nc])

                            if new_cost <= k:
                                new_score = dp[r][c][cost] + grid[nr][nc]

                                dp[nr][nc][new_cost] = max(
                                    dp[nr][nc][new_cost],
                                    new_score
                                )

        return max(dp[m - 1][n - 1])