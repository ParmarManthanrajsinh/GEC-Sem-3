-- Practical 2.6: Add a new column phone of type VARCHAR(15) to the students table.
-- Approach: ALTER TABLE ... ADD COLUMN.

ALTER TABLE students
ADD COLUMN phone VARCHAR(15);