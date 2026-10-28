-- Practical 2.21: Delete all students whose course id is not specified (NULL).
-- Approach: DELETE test_enrollments rows where course_id IS NULL.

DELETE FROM test_enrollments
WHERE course_id IS NULL;