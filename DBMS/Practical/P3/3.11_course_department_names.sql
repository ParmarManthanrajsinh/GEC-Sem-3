-- Practical 3.11: Display course names along with the department names they are part of.
-- Approach: Link courses to departments through course_faculty and faculty.

SELECT c.course_name, d.department_name
FROM courses c
JOIN course_faculty cf ON c.course_id = cf.course_id
JOIN faculty f ON cf.faculty_id = f.faculty_id
JOIN departments d ON f.department_id = d.department_id;
