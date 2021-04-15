class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        ret = []
        total = 0
        for n in nums:
            total += n
            ret += [total]
        return (ret)