class Solution:
    def countMatches(self, items: List[List[str]], ruleKey: str, ruleValue: str) -> int:
        match = 0
        cat = 0
        if (ruleKey == "color"):
            cat = 1
        elif (ruleKey == "name"):
            cat = 2
        for item in items:
            if (item[cat] == ruleValue):
                match += 1
        return (match)
