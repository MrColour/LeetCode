class Solution:
    def numberOfSteps(self, num: int) -> int:
        moves = 0
        while num != 0:
            if (num % 2 != 0):
                num -= 1
            else:
                num /= 2
            moves += 1
        return (moves)