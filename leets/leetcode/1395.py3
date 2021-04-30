def lined(rating):
    counts = [0] * len(rating)
    
    for i, num in enumerate(rating):
        for other in rating[i + 1:]:
            if (other < num):
                counts[i] += 1
                
    res = 0
    for i, num in enumerate(rating):
        if (counts[i] >= 2):
            for j, other in enumerate(rating[i + 1:]):
                if (num > other):
                    res += counts[j + i + 1]
    return (res)
        

class Solution:
    def numTeams(self, rating: List[int]) -> int:
        res = 0
        res += lined(rating)
        res += lined(rating[::-1])
        return (res)