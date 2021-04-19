class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        depth = 0
        gather = []
        for l in S:
            if (l == ')'):
                depth -= 1
            if (depth != 0):
                gather += l
            if (l == '('):
                depth += 1
        return "".join(gather)