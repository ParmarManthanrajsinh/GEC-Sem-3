-- Practical 2.5: Update all enrollments where grade is 'C' and change it to 'B'.
-- Approach: UPDATE grade for every row currently graded 'C'.

UPDATE enrollments
SET grade = 'B'
WHERE grade = 'C';