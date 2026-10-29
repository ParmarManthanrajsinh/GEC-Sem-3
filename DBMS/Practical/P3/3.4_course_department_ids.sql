-- Practical 3.4: Display course names with their corresponding department IDs.
-- Approach: A course has no department_id, so join courses to faculty via course_faculty.

SELECT c.course_name, f.department_id
FROM courses c
JOIN course_faculty cf ON c.course_id = cf.course_id
JOIN faculty f ON cf.faculty_id = f.faculty_id;
