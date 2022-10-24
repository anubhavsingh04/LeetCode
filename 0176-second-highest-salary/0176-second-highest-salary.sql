# Write your MySQL query statement below
# Note that instead of nesting for second, third, etc largest salary, we can find nth salary using general query like in MySQL: 
# SELECT salary 
# FROM employee 
# ORDER BY salary desc limit n-1,1

select(
    select distinct salary from Employee order by salary desc limit 1 offset 1
) as SecondHighestSalary ;