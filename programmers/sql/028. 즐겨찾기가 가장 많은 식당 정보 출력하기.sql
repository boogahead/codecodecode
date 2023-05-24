/*
https://school.programmers.co.kr/learn/courses/30/lessons/131123
*/
SELECT 
    FOOD_TYPE,
    REST_ID,
    REST_NAME,
    FAVORITES
FROM 
    REST_INFO
WHERE
    (FOOD_TYPE,FAVORITES) IN
    (SELECT FOOD_TYPE,MAX(FAVORITES)
    FROM REST_INFO
    GROUP BY FOOD_TYPE)
/*
WHERE IN 으로 가장 많은 FAVORITES 갖고있는 식당만 갖고와서 반영해주는거
*/
ORDER BY
    FOOD_TYPE DESC
/*
추가설명
https://school.programmers.co.kr/learn/courses/30/lessons/131123
https://monawa.tistory.com/125

SELECT FOOD_TYPE, REST_ID, REST_NAME, MAX(FAVORITES)
FROM REST_INFO
GROUP BY FOOD_TYPE
ORDER BY FOOD_TYPE DESC;
^내가 처음에 썼던거
이거 안되는 이유 : 
걍 food type끼리 묶으면 해당 food type으로 정렬되는 가장 위의 항목의 값만 나온다


*/
