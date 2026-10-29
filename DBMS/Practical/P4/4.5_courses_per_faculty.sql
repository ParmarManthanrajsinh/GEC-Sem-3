-- Practical 4.5: Count how many courses are offered by each faculty member.
-- Approach: COUNT per faculty over the course_faculty assignment table.

SELECT faculty_id, COUNT(course_id) AS course_count
FROM course_faculty
GROUP BY faculty_id;
