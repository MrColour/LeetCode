class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        sep = s.split(" ")
        return " ".join(sep[:k])