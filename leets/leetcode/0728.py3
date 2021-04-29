def isDigitDiv(num):
    digits = [int(l) for l in str(num)]

    for digit in digits:
        if (digit == 0):
            return (False)

        if (num % digit != 0):
            return (False)

    return (True)

class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        
        res = []
        for num in range(left, right + 1):
            if (isDigitDiv(num)):
                res += [num]

        return (res)