class Solution:
    def sortString(self, s: str) -> str:
        choosen = [0] * len(s)

        res = []
        s = sorted(s)
        while (min(choosen) == 0):

            prev = chr(0)
            for i in range(len(s)):
                if (choosen[i] == 0 and prev != s[i]):
                    res += s[i]
                    choosen[i] = 1
                    prev = s[i]

            prev = chr(0)
            for i in range(len(s) - 1, 0, -1):
                if (choosen[i] == 0 and prev != s[i]):
                    res += s[i]
                    choosen[i] = 1
                    prev = s[i]
        return ("".join(res))
