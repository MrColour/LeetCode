def traverse(curr_path, at, graph, gather):
    if (at == len(graph) - 1):
        gather += [curr_path]

    for connection in graph[at]:
        traverse(curr_path + [connection], connection, graph, gather)

class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        paths = []
        traverse([0], 0, graph, paths)
        return (paths)