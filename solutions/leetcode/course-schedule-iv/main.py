class Solution:

    def checkIfPrerequisite(self, num_courses: int,
                            prerequisites: List[List[int]],
                            queries: List[List[int]]) -> List[bool]:
        adj = [[] for _ in range(num_courses)]

        for a, b in prerequisites:
            adj[a].append(b)

        course_prerequisites = [set() for _ in range(num_courses)]

        for i in range(num_courses):
            seen = [False] * num_courses

            stack = [i]
            while len(stack) > 0:
                u = stack.pop()

                if seen[u]:
                    continue
                seen[u] = True

                for v in adj[u]:
                    course_prerequisites[v] = course_prerequisites[
                        v] | course_prerequisites[u] | {u}
                    stack.append(v)

        return [a in course_prerequisites[b] for a, b in queries]
