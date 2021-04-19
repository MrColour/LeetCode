class Solution:
    def minTimeToVisitAllPoints(self, points: List[List[int]]) -> int:
        time = 0
        prev = points[0]
        for point in points[1:]:
            xdel = abs(prev[0] - point[0])
            ydel = abs(prev[1] - point[1])
            time += min(xdel, ydel)
            time += max(xdel, ydel) - min(xdel, ydel)
        return (time) 