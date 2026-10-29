-- Practical 3.9: Show student IDs along with their department names.
-- Approach: INNER JOIN students to departments on department_id.

SELECT s.student_id, d.department_name
FROM students s
JOIN departments d ON s.department_id = d.department_id;
