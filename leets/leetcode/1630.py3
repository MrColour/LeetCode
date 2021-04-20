class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        res = []

        domain = zip(l, r)
        for dis in domain:
            check = sorted(nums[dis[0]: dis[1] + 1])
            dif = check[1] - check[0]
            for i in range(1, len(check)):
                if (dif != check[i] - check[i - 1]):
                    res += [False]
                    break
            else:
                res += [True]
        return (res)