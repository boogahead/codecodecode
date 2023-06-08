# Write your MySQL query statement below
SELECT
    max(SALARY) AS SecondHighestSalary
FROM
    EMPLOYEE
WHERE
    SALARY!=(SELECT MAX(SALARY) FROM EMPLOYEE)

# 가장 큰 연봉이 아닌 연봉 테이블 중에서 
# 가장 큰 연봉을 고르라는것 (그렇게 되면 두번째가 뽑히게 된다)
