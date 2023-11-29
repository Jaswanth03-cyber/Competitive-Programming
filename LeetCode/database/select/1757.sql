-- Write your PostgreSQL query statement below
-- https://leetcode.com/problems/recyclable-and-low-fat-products/

SELECT product_id 
FROM products 
WHERE products.low_fats = 'Y' and products.recyclable = 'Y' ;