/*
https://school.programmers.co.kr/learn/courses/30/lessons/132202
*/
SELECT
    MCDP_CD AS '진료과코드',
    COUNT(APNT_YMD) AS '5월예약건수'
FROM    
    APPOINTMENT
WHERE
    MONTH(APNT_YMD)=5
    AND YEAR(APNT_YMD)=2022
GROUP BY 
    MCDP_CD
ORDER BY 
    COUNT(APNT_YMD) ASC,
    MCDP_CD ASC
