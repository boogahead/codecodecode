# Write your MySQL query statement below
#SELECT E.NAME AS Employee
SELECT e.name as Employee
FROM (
  SELECT *
  FROM EMPLOYEE
  WHERE managerId is not null
 ) as E
JOIN EMPLOYEE M ON E.managerId=M.id
WHERE E.salary>M.salary
