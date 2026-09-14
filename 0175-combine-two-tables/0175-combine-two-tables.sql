# Write your MySQL query statement below
SELECT 
    Person.firstName,
    Person.lastname,
    Address.city,
    Address.state
FROM Person
Left join Address
ON person.personid = Address.personid