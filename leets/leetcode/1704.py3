def num_vowels(s):
    res = 0
    norm = s.lower()
    for vowel in "aeiou":
        res += norm.count(vowel)
    return (res)

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        s1 = s[:len(s) // 2]
        s2 = s[len(s) // 2:]

        if (num_vowels(s1) == num_vowels(s2)):
            return (True)
        else:
            return (False)
