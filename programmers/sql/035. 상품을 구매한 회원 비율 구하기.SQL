/*
https://school.programmers.co.kr/learn/courses/30/lessons/131534
*/
SELECT
    YEAR(SALES_DATE) AS YEAR,
    MONTH(SALES_DATE) AS MONTH,
    COUNT(DISTINCT USER_ID) AS PURCHASED_USERS, /* 여기까진 알겠지?*/
    ROUND(COUNT(DISTINCT USER_ID) / (SELECT COUNT(*) 
                                     FROM USER_INFO 
                                     WHERE YEAR(JOINED)=2021),1) AS PURCHASED_RATIO
    /*
    COUNT(DISTINCT USER_ID) : ONLINE SALE의 USER 수 새기
    /
    (SELECT COUNT(*) 
    FROM USER_INFO 
    WHERE YEAR(JOINED)=2021),1) AS PURCHASED_RATIO
    USER INFO 테이블에서 2021년에 가입한 전체 유저 수를 구해오는거
    */
FROM 
    ONLINE_SALE
WHERE
    USER_ID IN (SELECT USER_ID
                FROM USER_INFO
                WHERE YEAR(JOINED)=2021)
GROUP BY 
    YEAR(SALES_DATE),
    MONTH(SALES_DATE)
ORDER BY
    YEAR,
    MONTH
