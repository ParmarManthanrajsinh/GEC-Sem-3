-- Practical 2.3: Change the number of credits for the course "Database Systems" to 5.
-- Approach: UPDATE credits for the course matched by name.

UPDATE courses
SET credits = 5
WHERE course_name = 'Database Systems';