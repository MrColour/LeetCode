from collections import defaultdict

class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        cities = defaultdict(int)

        for pair in paths:
            cities[pair[0]] += 1
            cities[pair[1]] -= 1

        for city in cities:
            if (cities[city] < 0):
                return (city)
        return (None)