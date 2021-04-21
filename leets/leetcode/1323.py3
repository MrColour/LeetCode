class Solution:
    def maximum69Number (self, num: int) -> int:
        s = list(str(num))
        for i, l in enumerate(s):
            if (l == '6'):
                s[i] = '9'
                break
        
        return (int("".join(s)))