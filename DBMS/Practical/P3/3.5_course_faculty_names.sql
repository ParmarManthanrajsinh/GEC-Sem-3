-- Practical 3.5: Show course names and the names of faculty members who teach them.
-- Approach: INNER JOIN courses to faculty through the course_faculty bridge table.

SELECT c.course_name, f.name AS faculty_name
FROM courses c
JOIN course_faculty cf ON c.course_id = cf.course_id
JOIN faculty f ON cf.faculty_id = f.faculty_id;
