class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        choice = sorted(nums, reverse=True)

        return (choice[0] - 1) * (choice[1] - 1)