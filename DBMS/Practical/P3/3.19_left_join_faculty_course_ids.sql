-- Practical 3.19: LEFT JOIN: Show all faculty names with the course IDs they are teaching (if any).
-- Approach: LEFT JOIN faculty to course_faculty keeps faculty teaching no course.

SELECT f.name AS faculty_name, cf.course_id
FROM faculty f
LEFT JOIN course_faculty cf ON f.faculty_id = cf.faculty_id;
