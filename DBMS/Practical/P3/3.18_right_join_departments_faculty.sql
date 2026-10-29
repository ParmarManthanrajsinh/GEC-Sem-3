-- Practical 3.18: RIGHT JOIN: Display all departments with the names of faculty in each (if any).
-- Approach: RIGHT JOIN keeps every department even when it has no faculty.

SELECT d.department_name, f.name AS faculty_name
FROM faculty f
RIGHT JOIN departments d ON f.department_id = d.department_id;
