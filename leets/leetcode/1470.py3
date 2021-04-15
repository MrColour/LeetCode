class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ret = []
        for i in range(n):
            ret += [nums[i]]
            ret += [nums[i + n]]
        return (ret)
