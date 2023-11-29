-- Write your PostgreSQL query statement below
-- https://leetcode.com/problems/not-boring-movies/description/
SELECT Cinema.id, Cinema.movie, Cinema.description, Cinema.rating 
FROM Cinema 
WHERE Cinema.description not like 'boring' and MOD(Cinema.id, 2) = 1 
order by Cinema.rating desc ;