class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        for i, row in enumerate(image):
            for j, pixel in enumerate(row[::-1]):
                image[i][j] = pixel ^ 1
        return (image)
                
            