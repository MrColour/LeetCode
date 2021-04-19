class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        
        transform = []
        for word in words:
            gather = []
            for l in word:
                gather += morse[ord(l) - ord('a')]
            transform += ["".join(gather)]

        transform = set(transform)
        return (len(transform))
