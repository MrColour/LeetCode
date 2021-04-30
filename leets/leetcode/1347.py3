from collections import defaultdict

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        counts = defaultdict(int)

        for l in s:
            counts[l] += 1

        print(counts)

        for l in t:
            counts[l] -= 1

        res = 0
        for key in counts:
            res += abs(counts[key])

        return (res // 2)