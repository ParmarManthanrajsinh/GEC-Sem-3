-- Practical 2.2: Update all students from department ID 3 to department ID 2.
-- Approach: UPDATE department_id for every row matching department 3.

UPDATE students
SET department_id = 2
WHERE department_id = 3;