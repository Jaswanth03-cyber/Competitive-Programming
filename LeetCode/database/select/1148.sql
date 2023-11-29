-- Write your PostgreSQL query statement below
-- https://leetcode.com/problems/article-views-i/description
SELECT distinct (Views.author_id) as id 
FROM Views 
WHERE Views.author_id = Views.viewer_id order by Views.author_id ;