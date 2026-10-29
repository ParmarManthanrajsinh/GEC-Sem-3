-- Practical 4.12: Show the name of each student along with their name reversed.
-- Approach: Use the REVERSE() string function on the name column.

SELECT name, REVERSE(name) AS reversed_name
FROM students;
