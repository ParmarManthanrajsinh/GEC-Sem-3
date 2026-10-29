-- Practical 4.14: Group courses by credit value and count how many courses fall under each credit.
-- Approach: GROUP BY credits with COUNT(*).

SELECT credits, COUNT(*) AS course_count
FROM courses
GROUP BY credits;
