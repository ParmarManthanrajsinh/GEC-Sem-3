-- Practical 3.2: Display faculty names with the names of their departments.
-- Approach: INNER JOIN faculty to departments on department_id.

SELECT f.name AS faculty_name, d.department_name
FROM faculty f
JOIN departments d ON f.department_id = d.department_id;
