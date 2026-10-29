-- Practical 2.13: Modify the semester column to set its default value to 4.
-- Approach: ALTER TABLE ... MODIFY COLUMN with DEFAULT.

ALTER TABLE courses
MODIFY COLUMN semester INT DEFAULT 4;