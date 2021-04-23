class Solution:
    def generateTheString(self, n: int) -> str:
        res = ['a'] * n
        if (n % 2 == 0):
            res[0] = 'b'
        return ("".join(res))