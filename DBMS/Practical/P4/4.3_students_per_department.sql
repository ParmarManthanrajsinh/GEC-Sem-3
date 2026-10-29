-- Practical 4.3: Find the total number of students in each department.
-- Approach: JOIN students to departments and COUNT per department with GROUP BY.

SELECT d.department_name, COUNT(s.student_id) AS total_students
FROM departments d
JOIN students s ON d.department_id = s.department_id
GROUP BY d.department_id, d.department_name;
