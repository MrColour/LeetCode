class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        pairs = 0
        for i in range(len(nums)):
            catch = nums[i]
            for n in nums[i + 1:]:
                if (n == catch):
                    pairs += 1
        return (pairs)