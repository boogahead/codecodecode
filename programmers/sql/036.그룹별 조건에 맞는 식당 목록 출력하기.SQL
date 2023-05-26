/*
https://school.programmers.co.kr/learn/courses/30/lessons/131124
*/
SELECT
    MEM.MEMBER_NAME,
    RES.REVIEW_TEXT,
    DATE_FORMAT(RES.REVIEW_DATE,'%Y-%m-%d') AS REVIEW_DATE
FROM
    MEMBER_PROFILE MEM
JOIN REST_REVIEW RES
    ON MEM.MEMBER_ID=RES.MEMBER_ID
WHERE
    RES.MEMBER_ID= (SELECT MEMBER_ID 
                    FROM REST_REVIEW
                    GROUP BY MEMBER_ID
                    ORDER BY COUNT(MEMBER_ID) DESC
                    LIMIT 1)
/*
SUBQUERY 안에 LIMIT 쓸꺼면 IN 이 아니라 =을 써야한다
*/
ORDER BY 
    RES.REVIEW_DATE,
    RES.REVIEW_TEXT
