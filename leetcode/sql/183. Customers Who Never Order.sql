# Write your MySQL query statement below
SELECT c.name as Customers
FROM Customers c
left outer join Orders o on c.id=o.customerId
where o.customerId is null
