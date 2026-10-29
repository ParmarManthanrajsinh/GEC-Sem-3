-- Practical 3.1: Display student names along with their department names.
-- Approach: INNER JOIN students to departments on department_id.

SELECT s.name AS student_name, d.department_name
FROM students s
JOIN departments d ON s.department_id = d.department_id;
