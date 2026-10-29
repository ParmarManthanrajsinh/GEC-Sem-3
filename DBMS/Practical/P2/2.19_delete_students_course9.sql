-- Practical 2.19: Delete all students who belong to course_ID 9.
-- Approach: In test_enrollments each row links a student to a course - delete rows for course 9.

DELETE FROM test_enrollments
WHERE course_id = 9;