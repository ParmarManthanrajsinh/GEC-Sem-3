-- Practical 4.4: Display the maximum number of credits assigned to any course.
-- Approach: MAX(credits) over the courses table.

SELECT MAX(credits) AS max_credits
FROM courses;
