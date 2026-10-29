-- Practical 3.16: LEFT JOIN: List all students with their enrolled course IDs (if any).
-- Approach: LEFT JOIN students to enrollments keeps students with no enrollment.

SELECT s.name AS student_name, e.course_id
FROM students s
LEFT JOIN enrollments e ON s.student_id = e.student_id;
