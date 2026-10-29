-- Practical 4.6: Show the minimum student ID in the students table.
-- Approach: MIN(student_id) over the students table.

SELECT MIN(student_id) AS min_student_id
FROM students;
