-- Practical 3.12: List student names with the course names they are enrolled in.
-- Approach: INNER JOIN students to courses through enrollments.

SELECT s.name AS student_name, c.course_name
FROM students s
JOIN enrollments e ON s.student_id = e.student_id
JOIN courses c ON e.course_id = c.course_id;
