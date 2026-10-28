-- Practical 2.1: Update the email address of the student with student ID 101 to alice.shah@college.edu.
-- Approach: UPDATE the email column for the matching student row.

UPDATE students
SET email = 'alice.shah@college.edu'
WHERE student_id = 101;