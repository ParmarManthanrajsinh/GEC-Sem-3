-- Practical 4.8: Show the length of each course name.
-- Approach: Apply LENGTH() to each course_name.

SELECT course_name, LENGTH(course_name) AS name_length
FROM courses;
