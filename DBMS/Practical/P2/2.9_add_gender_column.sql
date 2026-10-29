-- Practical 2.9: Add a column gender of type CHAR(1) to the faculty table.
-- Approach: ALTER TABLE ... ADD COLUMN.

ALTER TABLE faculty
ADD COLUMN gender CHAR(1);