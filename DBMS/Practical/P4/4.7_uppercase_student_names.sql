-- Practical 4.7: Display the names of all students in uppercase.
-- Approach: Apply the UPPER() string function to the name column.

SELECT UPPER(name) AS student_name_upper
FROM students;
