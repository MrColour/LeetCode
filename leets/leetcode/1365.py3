class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        ordered = sorted(nums)
        ret = []
        for n in nums:
            ret += [ordered.index(n)]
        return (ret)