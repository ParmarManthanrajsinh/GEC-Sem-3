-- Practical 4.18: Display departments with more than 3 students.
-- Approach: GROUP BY department_id and keep groups with COUNT(*) > 3 using HAVING.

SELECT department_id, COUNT(*) AS student_count
FROM students
GROUP BY department_id
HAVING COUNT(*) > 3;
