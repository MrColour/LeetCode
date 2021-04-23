class Solution:
    def busyStudent(self, startTime: List[int], endTime: List[int], queryTime: int) -> int:
        res = 0

        for i, start in enumerate(startTime):
            if (start <= queryTime):
                if (endTime[i] >= queryTime):
                    res += 1

        return (res)