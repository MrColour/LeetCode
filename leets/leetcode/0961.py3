from collections import Counter

class Solution:
    def repeatedNTimes(self, A: List[int]) -> int:
        most = Counter(A).most_common(1)[0][0]
        return (most)