-- Practical 4.19: List faculty members who are assigned more than 2 courses.
-- Approach: GROUP BY faculty_id and keep groups with COUNT(*) > 2 using HAVING.

SELECT faculty_id, COUNT(course_id) AS course_count
FROM course_faculty
GROUP BY faculty_id
HAVING COUNT(course_id) > 2;
