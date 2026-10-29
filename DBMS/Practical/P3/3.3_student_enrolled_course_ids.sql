-- Practical 3.3: Show student names and the course IDs they are enrolled in.
-- Approach: INNER JOIN students to enrollments on student_id.

SELECT s.name AS student_name, e.course_id
FROM students s
JOIN enrollments e ON s.student_id = e.student_id;
