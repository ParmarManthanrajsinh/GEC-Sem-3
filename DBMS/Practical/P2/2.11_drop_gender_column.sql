-- Practical 2.11: Remove the gender column from the faculty table.
-- Approach: ALTER TABLE ... DROP COLUMN.

ALTER TABLE faculty
DROP COLUMN gender;