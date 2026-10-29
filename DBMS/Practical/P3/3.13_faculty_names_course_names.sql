-- Practical 3.13: Show faculty names and the names of courses they are teaching.
-- Approach: INNER JOIN faculty to courses through course_faculty.

SELECT f.name AS faculty_name, c.course_name
FROM faculty f
JOIN course_faculty cf ON f.faculty_id = cf.faculty_id
JOIN courses c ON cf.course_id = c.course_id;
