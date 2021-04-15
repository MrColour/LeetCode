class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        greatest = max(candies)
        ret = []
        for kid in candies:
            if (kid + extraCandies >= greatest):
                ret += [True]
            else:
                ret += [False]
        return (ret)