class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        evens = [(len(str(x)) - 1) % 2 for x in nums]
        return (sum(evens))
