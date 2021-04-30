class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        count = 0
        res = 0
        for l in S:
            if (l == '('):
                count += 1
            elif (count == 0):
                res += 1
            else:
                count -= 1

        return (res + count)
