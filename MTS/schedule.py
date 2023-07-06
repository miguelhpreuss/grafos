class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adjacency = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        
        for course, prereq in prerequisites:
            adjacency[prereq].append(course)
            indegree[course] += 1
        
        queue = []
        for course in range(numCourses):
            if indegree[course] == 0:
                queue.append(course)
        
        order = []
        while queue:
            course = queue.pop(0)
            order.append(course)
            
            for neighbor in adjacency[course]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
        
        if len(order) == numCourses:
            return order
        else:
            return []
