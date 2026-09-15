# Write your MySQL query statement below
SELECT c.name AS customers
FROM customers c
LEFT JOIN Orders o
  on c.id = o.customerID
WHERE o.customerID IS NULL
