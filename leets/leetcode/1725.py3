class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        sqln = []
        for rect in rectangles:
            sqln += [min(rect[0], rect[1])]

        sqln.sort()
        return (sqln.count(sqln[-1]))