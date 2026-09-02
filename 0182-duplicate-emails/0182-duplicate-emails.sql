# Write your MySQL query statement below
SELECT email
FROM Person
GROUP by email
HAVING COUNT(email)>1
