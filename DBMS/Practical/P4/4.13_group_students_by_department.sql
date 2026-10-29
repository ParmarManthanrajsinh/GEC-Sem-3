-- Practical 4.13: Group students by department and display the count of students in each.
-- Approach: GROUP BY department_id with COUNT(*).

SELECT department_id, COUNT(*) AS student_count
FROM students
GROUP BY department_id;
