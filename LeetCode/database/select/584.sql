-- Write your PostgreSQL query statement below
-- https://leetcode.com/problems/find-customer-referee/
SELECT Customer.name 
FROM Customer 
WHERE Customer.referee_id is null or Customer.referee_id <> 2 ;