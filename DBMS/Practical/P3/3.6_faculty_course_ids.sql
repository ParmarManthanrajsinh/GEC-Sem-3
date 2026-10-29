-- Practical 3.6: List faculty names and the course IDs they are assigned to.
-- Approach: INNER JOIN faculty to course_faculty on faculty_id.

SELECT f.name AS faculty_name, cf.course_id
FROM faculty f
JOIN course_faculty cf ON f.faculty_id = cf.faculty_id;
