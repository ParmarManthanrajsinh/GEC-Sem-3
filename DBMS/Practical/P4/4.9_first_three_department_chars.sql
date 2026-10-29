-- Practical 4.9: Display the first 3 characters of each department name.
-- Approach: Use SUBSTRING(department_name, 1, 3).

SELECT department_name, SUBSTRING(department_name, 1, 3) AS short_name
FROM departments;
