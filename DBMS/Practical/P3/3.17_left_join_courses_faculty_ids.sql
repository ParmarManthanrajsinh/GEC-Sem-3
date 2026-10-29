-- Practical 3.17: LEFT JOIN: Show all courses along with their assigned faculty IDs (if any).
-- Approach: LEFT JOIN courses to course_faculty keeps courses with no assigned faculty.

SELECT c.course_name, cf.faculty_id
FROM courses c
LEFT JOIN course_faculty cf ON c.course_id = cf.course_id;
