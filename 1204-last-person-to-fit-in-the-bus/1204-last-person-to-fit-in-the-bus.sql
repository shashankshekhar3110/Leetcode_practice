# Write your MySQL query statement below
SELECT person_name
FROM Queue
WHERE turn = (
    SELECT MAX(turn)
    FROM Queue
    WHERE (
        SELECT SUM(q2.weight)
        FROM Queue q2
        WHERE q2.turn <= Queue.turn
    ) <= 1000
); 