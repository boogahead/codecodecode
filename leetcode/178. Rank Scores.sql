# Write your MySQL query statement below
SELECT 
    SCORE,
    dense_rank() over( order by score desc) as 'rank'
FROM 
    SCORES
# making use of dense_rank
# dense_rank is a window function. It literally gives ranks to each rows and dups are considered same rank  
# window function performs its operation on each of the query rows.
