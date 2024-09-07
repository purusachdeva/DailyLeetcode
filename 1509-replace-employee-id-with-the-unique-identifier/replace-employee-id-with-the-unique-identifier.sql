# Write your MySQL query statement below

SELECT second.unique_id , first.name 
FROM Employees as first left join EmployeeUNI as second
ON first.id = second.id;