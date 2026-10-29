-- Practical 4.17: Display the average student ID (numerically) per department.
-- Approach: GROUP BY department_id with AVG(student_id).

SELECT department_id, AVG(student_id) AS average_student_id
FROM students
GROUP BY department_id;
