from collections import deque
from typing import List


class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates


def getImportance(self, employees: List['Employee'], id: int) -> int:
    importance = 0
    emps = {}
    for emp in employees:
        emps[emp.id] = emp
        
    if id in emps:
        queue = deque()
        queue.append(id)

        while queue:
            emp_id = queue.popleft()
            employee = emps[emp_id]
            
            importance += employee.importance
            
            for sub in employee.subordinates:
                queue.append(sub)  
                
    return importance