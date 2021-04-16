from collections import deque

class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        size = max(index)

        ret = deque()
        for i in range(len(index)):
            ret.insert(index[i], nums[i])
        print(ret)
        return (ret)