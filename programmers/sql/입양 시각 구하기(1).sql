/*
https://school.programmers.co.kr/learn/courses/30/lessons/59412
*/
SELECT 
    HOUR(DATETIME) AS HOUR,
    COUNT(HOUR(DATETIME)) AS 'COUNT'
FROM ANIMAL_OUTS
WHERE 
    HOUR(DATETIME)>=9
    AND HOUR(DATETIME)<20
GROUP BY HOUR(DATETIME)
ORDER BY HOUR(DATETIME)
