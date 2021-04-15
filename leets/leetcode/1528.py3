class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        new = list(s)
        for i in range(len(indices)):
            new[indices[i]] = s[i]
        return "".join(new)
