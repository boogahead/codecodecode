# Write your MySQL query statement below
SELECT UNI.unique_id,name
FROM EMPLOYEES E
LEFT JOIN EmployeeUNI UNI ON E.ID = UNI.id
