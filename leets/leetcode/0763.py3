def partition(letters, s):
    if (len(s) <= 0):
        return (True)
    for l in letters:
        if l in s:
            return (False)
    return (True)

class Solution:
    def partitionLabels(self, S: str) -> List[int]:

        res = []
        remain = S
        while (len(remain) > 0):
            looking = set([remain[0]])

            move = 1
            remain = remain[1:]
            while (partition(looking, remain) == False):
                add = []
                big = 0
                for l in looking:
                    if (l in remain):
                        if (big < remain.index(l)):
                            big = remain.index(l)
                for i in range(big):
                    if (remain[i] not in looking):
                        add += remain[i]

                remain = remain[big + 1:]
                move += big + 1
                for l in add:
                    looking.add(l)

            res += [move]

        return (res)


            