/*
https://school.programmers.co.kr/learn/courses/30/lessons/133027
*/
SELECT
    J.FLAVOR
FROM 
    (SELECT 
        SHIPMENT_ID,
        FLAVOR,
        SUM(TOTAL_ORDER) AS TOTAL_ORDER
    FROM JULY
    GROUP BY FLAVOR) J
JOIN FIRST_HALF H ON
    J.SHIPMENT_ID=H.SHIPMENT_ID
ORDER BY J.TOTAL_ORDER+H.TOTAL_ORDER DESC
LIMIT 3
/*
FROM 할때 JULY 테이블에서 같은 FLAVOR들은 다 합친채로 테이블을 만들어다가 뱉어내게 한다
*/
