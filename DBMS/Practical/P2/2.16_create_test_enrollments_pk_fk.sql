-- Practical 2.16: Create test_enrollments (enroll_id, student_id, course_id) and add primary/foreign key constraints.
-- Approach: CREATE TABLE, then ALTER TABLE to add the primary key and two foreign keys.

CREATE TABLE test_enrollments (
    enroll_id INT,
    student_id INT,
    course_id INT
);

ALTER TABLE test_enrollments
ADD PRIMARY KEY (enroll_id);

ALTER TABLE test_enrollments
ADD FOREIGN KEY (student_id) REFERENCES students(student_id);

ALTER TABLE test_enrollments
ADD FOREIGN KEY (course_id) REFERENCES courses(course_id);