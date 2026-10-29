-- Practical 2.22: Delete all courses having student_id=1.
-- Approach: In test_enrollments each row links a course to a student - delete rows for student 1.

DELETE FROM test_enrollments
WHERE student_id = 1;