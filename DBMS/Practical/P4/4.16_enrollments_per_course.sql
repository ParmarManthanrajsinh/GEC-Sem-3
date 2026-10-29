-- Practical 4.16: Show total number of enrollments per course.
-- Approach: GROUP BY course_id with COUNT(*).

SELECT course_id, COUNT(*) AS enrollment_count
FROM enrollments
GROUP BY course_id;
