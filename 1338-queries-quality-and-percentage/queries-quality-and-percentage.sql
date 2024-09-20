# Write your MySQL query statement below

SELECT 
    query_name,
    ROUND(SUM(rating / position) / COUNT(*), 2) as quality,
    ROUND(SUM(if(rating < 3, 1, 0)) / COUNT(*) * 100, 2) as poor_query_percentage
FROM
    Queries
WHERE
    query_name is not null
GROUP BY
    query_name