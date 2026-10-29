-- Practical 4.15: Group faculty by department and display the number of faculty members per department.
-- Approach: GROUP BY department_id with COUNT(*).

SELECT department_id, COUNT(*) AS faculty_count
FROM faculty
GROUP BY department_id;
