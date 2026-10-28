-- Practical 2.8: Remove the phone column from the students table.
-- Approach: ALTER TABLE ... DROP COLUMN.

ALTER TABLE students
DROP COLUMN phone;