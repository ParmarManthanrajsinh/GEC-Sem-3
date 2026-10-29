-- Practical 2.14: Remove the semester column from the courses table.
-- Approach: ALTER TABLE ... DROP COLUMN.

ALTER TABLE courses
DROP COLUMN semester;