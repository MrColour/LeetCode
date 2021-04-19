class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        high = 0
        total = 0
        for num in gain:
            total += num
            if (total > high):
                high = total

        return (high)