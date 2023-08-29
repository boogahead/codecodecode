# Write your MySQL query statement below
SELECT 
  DISTINCT a.id
FROM
  Weather a
JOIN
  Weather b ON DATEDIFF(a.recordDate,b.recordDate)=1 AND a.temperature>b.temperature
