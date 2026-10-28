-- Practical 2.12: Add a new column semester (INT) to the courses table.
-- Approach: ALTER TABLE ... ADD COLUMN.

ALTER TABLE courses
ADD COLUMN semester INT;