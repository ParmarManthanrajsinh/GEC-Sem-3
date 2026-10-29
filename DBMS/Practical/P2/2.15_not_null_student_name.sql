-- Practical 2.15: Modify the name column in the students table to ensure it cannot be NULL.
-- Approach: ALTER TABLE ... MODIFY COLUMN with NOT NULL.

ALTER TABLE students
MODIFY COLUMN name VARCHAR(100) NOT NULL;