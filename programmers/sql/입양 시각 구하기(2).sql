/*
https://school.programmers.co.kr/learn/courses/30/lessons/59413
*/
SET @HOUR= -1;
SELECT
    (@HOUR := @HOUR+1) AS HOUR,
    (SELECT 
        COUNT(DATETIME)
     FROM ANIMAL_OUTS
     WHERE HOUR(DATETIME)=@HOUR
    ) AS COUNT
FROM 
    ANIMAL_OUTS
WHERE @HOUR<23
/*
SET : 변수설정할때 사용. 변수 hour을 설정하려면 앞에 @을 붙여줘야 한다 -> @HOUR
@HOUR := @HOUR + 1 : 원래 hour = hour+1 이렇게 하는거에서 = 을 sql에서는 :=으로 써줘야 한다
WHERE @HOUR<23 @HOUR가 23까지만 가야하므로 리밋 설정
*/
