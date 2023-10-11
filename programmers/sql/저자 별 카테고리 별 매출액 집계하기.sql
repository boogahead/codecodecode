SELECT 
    B.AUTHOR_ID,
    AUTHOR_NAME,
    CATEGORY,
    SUM(BS.SALES*B.PRICE) AS TOTAL_SALES
FROM BOOK B
JOIN AUTHOR A ON B.AUTHOR_ID=A.AUTHOR_ID
JOIN BOOK_SALES BS ON B.BOOK_ID=BS.BOOK_ID
WHERE YEAR(BS.SALES_DATE)=2022 AND MONTH(BS.SALES_DATE)=1
GROUP BY A.AUTHOR_ID,CATEGORY
ORDER BY B.AUTHOR_ID ASC, B.CATEGORY DESC
# https://school.programmers.co.kr/learn/courses/30/lessons/144856
'''
SUM( BS.SALES * B.PRICE )는 맞고 
SUM ( BS.SALES ) * B.PRICE 는 틀린 이유
한 작가가 같은 카테고리로 여러 책을 썼을수도 있다 ( E.G. 홍길동이 경제에 관련된 책 A 와 B 를 썼을수도 있다)
그럴때 그냥 PRICE 한개로 해다가 곱해버리면 안된다

'''
