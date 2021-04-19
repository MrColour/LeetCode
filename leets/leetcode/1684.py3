class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        match = 0

        for word in words:
            nope = False
            for l in word:
                if (l not in allowed):
                    nope = True
                    break

            if (nope == False):
                match += 1
        return (match)