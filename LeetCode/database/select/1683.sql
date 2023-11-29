-- Write your PostgreSQL query statement below
-- https://leetcode.com/problems/invalid-tweets/description/
SELECT Tweets.tweet_id 
FROM Tweets 
WHERE length(Tweets.content) > 15 ;