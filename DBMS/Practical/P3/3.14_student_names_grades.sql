-- Practical 3.14: Display student names along with the grades they received.
-- Approach: INNER JOIN students to enrollments on student_id.

SELECT s.name AS student_name, e.grade
FROM students s
JOIN enrollments e ON s.student_id = e.student_id;
