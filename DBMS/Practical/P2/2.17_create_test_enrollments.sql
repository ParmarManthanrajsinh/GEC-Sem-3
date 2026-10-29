-- Practical 2.17: Create a new table named test_enrollments with columns enroll_id, student_id, and course_id.
-- Approach: CREATE TABLE IF NOT EXISTS so the file still runs after 2.16.

CREATE TABLE IF NOT EXISTS test_enrollments (
    enroll_id INT,
    student_id INT,
    course_id INT
);