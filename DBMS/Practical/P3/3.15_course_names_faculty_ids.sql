-- Practical 3.15: List course names with faculty IDs teaching those courses.
-- Approach: INNER JOIN courses to course_faculty on course_id.

SELECT c.course_name, cf.faculty_id
FROM courses c
JOIN course_faculty cf ON c.course_id = cf.course_id;
