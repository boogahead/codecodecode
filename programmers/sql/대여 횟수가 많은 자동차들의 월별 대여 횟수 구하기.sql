#어려웠음
SELECT 
    MONTH(START_DATE) AS MONTH,
    CAR_ID,
    COUNT(HISTORY_ID) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE CAR_ID IN
    (SELECT 
        CAR_ID
    FROM 
        CAR_RENTAL_COMPANY_RENTAL_HISTORY
    WHERE 
        MONTH(START_DATE)>=8 AND MONTH(START_DATE)<=10 AND YEAR(START_DATE)=2022
    GROUP BY 
        CAR_ID
    HAVING 
        COUNT(CAR_ID)>=5
    )
    AND 
        MONTH(START_DATE)>=8 AND MONTH(START_DATE)<=10 AND YEAR(START_DATE)=2022
GROUP BY 
    MONTH(START_DATE),CAR_ID
HAVING 
    COUNT(HISTORY_ID)>0
ORDER BY 
    MONTH(START_DATE)ASC,
    CAR_ID DESC
'''
https://school.programmers.co.kr/learn/courses/30/lessons/151139

가장 먼저 서브쿼리를 이용해서 해당 기간 안에 5번 이상 렌트한 차들 아이디를 싹 모음
여기서 나온 아이디들이 있긴 하지만 얘네는 원 테이블에서는 다른 기간에 빌린 애들도 있으므로, 다시 기간을 where을 통해 설정해준다

거기서 나온애들중에 month, car id 로 그룹해주고 
카운트 1 이상인애들만 쳐준다


https://velog.io/@dl-00-e8/Programmers-%EB%8C%80%EC%97%AC-%ED%9A%9F%EC%88%98%EA%B0%80-%EB%A7%8E%EC%9D%80-%EC%9E%90%EB%8F%99%EC%B0%A8%EB%93%A4%EC%9D%98-%EC%9B%94%EB%B3%84-%EB%8C%80%EC%97%AC-%ED%9A%9F%EC%88%98-%EA%B5%AC%ED%95%98%EA%B8%B0


'''
