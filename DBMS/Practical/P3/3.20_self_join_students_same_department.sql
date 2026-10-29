-- Practical 3.20: SELF JOIN: List pairs of students who belong to the same department.
-- Approach: SELF JOIN students to itself on equal department_id, avoiding duplicate pairs.

SELECT s1.name AS student_1, s2.name AS student_2, s1.department_id
FROM students s1
JOIN students s2
  ON s1.department_id = s2.department_id
 AND s1.student_id < s2.student_id;
