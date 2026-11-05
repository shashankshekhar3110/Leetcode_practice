# Write your MySQL query statement below
SELECT name FROM Employee
WHERE id IN( 
     select managerid
     from employee
     group by managerid
     having count(managerid) >= 5
)