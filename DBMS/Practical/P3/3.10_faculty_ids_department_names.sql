-- Practical 3.10: Show faculty IDs and the names of the departments they belong to.
-- Approach: INNER JOIN faculty to departments on department_id.

SELECT f.faculty_id, d.department_name
FROM faculty f
JOIN departments d ON f.department_id = d.department_id;
