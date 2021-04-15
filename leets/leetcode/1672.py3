class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        most = 0
        for banks in accounts:
            total = sum(banks)
            if (total > most):
                most = total
        return (most)