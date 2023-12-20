# Write your MySQL query statement below
SELECT d.name Department,e.name Employee,e.salary Salary
FROM department d
JOIN Employee e on d.id=e.departmentId
WHERE (e.departmentId,e.salary) in
(SELECT departmentId,Max(salary)
FROM Employee
Group by departmentId)
