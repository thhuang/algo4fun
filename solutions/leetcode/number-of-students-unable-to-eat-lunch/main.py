class Solution:

    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        for i, v in enumerate(sandwiches):
            assigned = False
            for j in range(len(students)):
                if students[j] != sandwiches[i]:
                    continue
                assigned = True
                students = students[:j] + students[j + 1:]
                break
            if not assigned:
                return len(sandwiches) - i
        return 0
