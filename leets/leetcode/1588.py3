class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        total = 0
        for i in range(1, len(arr) + 1, 2):
            prev = arr[0]
            accum = sum(arr[0:i])
            total += accum
            for j in range(i, len(arr)):
                accum += arr[j]
                accum -= prev
                prev = arr[j - i + 1]
                total += accum

        return (total)