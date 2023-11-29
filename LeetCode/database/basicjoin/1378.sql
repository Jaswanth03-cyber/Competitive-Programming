-- https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/=
-- Write your PostgreSQL query statement below
SELECT EmployeeUNI.unique_id, Employees.name 
FROM Employees left outer join EmployeeUNI 
ON Employees.id = EmployeeUNI.id ;