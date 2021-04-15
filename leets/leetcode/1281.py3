class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        nums = list(map(int, str(n)))
        s = sum(nums)
        p = reduce(lambda x, y: x * y, nums, 1)
        return (p - s)