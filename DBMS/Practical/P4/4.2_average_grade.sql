-- Practical 4.2: Show the average grade (assuming letter grades are mapped to numbers) for all enrollments.
-- Approach: Map A/B/C/D to 4/3/2/1 with CASE, then AVG the mapped values.

SELECT AVG(CASE grade
               WHEN 'A' THEN 4
               WHEN 'B' THEN 3
               WHEN 'C' THEN 2
               WHEN 'D' THEN 1
               ELSE 0
           END) AS average_grade
FROM enrollments;
