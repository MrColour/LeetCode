class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        first = ord(coordinates[0]) - ord('a')
        second = int(coordinates[1])
        
        second -= 1
        first += second
        if (first % 2 == 0):
            return (False)
        else:
            return (True)