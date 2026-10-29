-- Practical 3.7: Show student names and their grades for the courses they are enrolled in.
-- Approach: INNER JOIN students to enrollments on student_id.

SELECT s.name AS student_name, e.grade
FROM students s
JOIN enrollments e ON s.student_id = e.student_id;
