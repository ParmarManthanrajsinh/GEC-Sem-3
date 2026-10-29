-- Practical 3.8: Display course names and the student IDs of enrolled students.
-- Approach: INNER JOIN courses to enrollments on course_id.

SELECT c.course_name, e.student_id
FROM courses c
JOIN enrollments e ON c.course_id = e.course_id;
