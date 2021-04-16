from collections import Counter

class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        most = edges[0] + edges[1]
        cen = Counter(most).most_common(1)[0][0]
        return (cen)
        
