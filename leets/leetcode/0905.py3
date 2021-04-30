class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        even = []
        odd = []

        for num in A:
            if (num % 2 == 0):
                even += [num]
            else:
                odd += [num]

        return (even + odd)
