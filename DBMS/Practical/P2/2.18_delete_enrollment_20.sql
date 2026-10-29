-- Practical 2.18: Delete the enrollment record with enrollment ID 20.
-- Approach: DELETE the test_enrollments row whose enroll_id is 20.

DELETE FROM test_enrollments
WHERE enroll_id = 20;