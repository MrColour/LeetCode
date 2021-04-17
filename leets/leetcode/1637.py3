class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        p = [point[0] for point in points]
        p = sorted(p)

        wide = 0
        prev = p[0]
        for x in p:
            if (wide < x - prev):
                wide = (x - prev)
            prev = x
        return (wide) 