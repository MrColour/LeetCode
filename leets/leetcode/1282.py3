class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        res = []
        used = [0] * len(groupSizes)

        for i in range(len(groupSizes)):
            add = []
            if (used[i] == 1):
                continue

            missing = groupSizes[i]
            for j in range(i, len(groupSizes)):
                if (missing == 0):
                    break
                if (used[j] == 0 and groupSizes[j] == groupSizes[i]):
                    add += [j]
                    used[j] = 1
                    missing -= 1
            res += [add]
        return (res)
