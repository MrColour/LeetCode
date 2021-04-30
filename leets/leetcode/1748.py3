from collections import Counter

class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        freq = Counter(nums)

        res = 0
        for pair in freq.most_common():
            if (pair[1] == 1):
                res += pair[0]
        return (res)