class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        moves = []
        for i in range(len(boxes)):
            dis = 0
            for j in range(len(boxes)):
                if (boxes[j] == '1'):
                    dis += abs(i - j)
            moves += [dis]
        return (moves)