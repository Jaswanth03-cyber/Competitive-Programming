-- Write your PostgreSQL query statement below
-- https://leetcode.com/problems/product-sales-analysis-i/
SELECT Product.product_name, Sales.year, Sales.price 
FROM Sales natural join Product ;