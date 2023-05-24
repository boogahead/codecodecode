/*
https://school.programmers.co.kr/learn/courses/30/lessons/151137
*/
SELECT 
    CAR_TYPE,
    COUNT(CAR_TYPE) AS CARS
FROM 
    CAR_RENTAL_COMPANY_CAR
WHERE
    OPTIONS LIKE '%통풍시트%'
    OR OPTIONS LIKE '%열선시트%'
    OR OPTIONS LIKE '%가죽시트%'
GROUP BY 
    CAR_TYPE
ORDER BY CAR_TYPE ASC
/*
STRING 에 특정 단어있는지 확인 위해서는 OPTIONS LIKE '%통풍시트'  <- 통풍시트라는 단어가 들어있는지 
확인한다
*/
