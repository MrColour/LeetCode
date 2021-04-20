from collections import defaultdict

class Solution:
    def findingUsersActiveMinutes(self, logs: List[List[int]], k: int) -> List[int]:
        users = defaultdict(set)

        for log in logs:
            users[log[0]].add(log[1])

        print(users)
        res = [0] * k
        for mins in users:
            if (len(users[mins]) <= k):
                res[len(users[mins]) - 1] += 1
        return (res)