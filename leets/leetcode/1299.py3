class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        new = arr[::-1]
        high = new[0]

        for i, num in enumerate(new):
            if (num > high):
                new[i], high = high, num
            else:
                new[i] = high

        new[0] = -1
        return (new[::-1])
