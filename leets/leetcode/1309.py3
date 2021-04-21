class Solution:
    def freqAlphabets(self, s: str) -> str:
        gather = []

        i = 0
        while (i < len(s)):
            print(s[i:])
            if (i + 2 < len(s) and s[i + 2] == '#'):
                l = chr(ord('a') + int(s[i:i+2]) - 1)
                i += 2
            else:
                l = chr(ord('a') + int(s[i]) - 1)
            gather += [l]
            i += 1

        return ("".join(gather))