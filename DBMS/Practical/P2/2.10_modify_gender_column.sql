-- Practical 2.10: Modify the gender column in the faculty table to be VARCHAR(6) to store values like "Male" or "Female".
-- Approach: ALTER TABLE ... MODIFY COLUMN to widen the data type.

ALTER TABLE faculty
MODIFY COLUMN gender VARCHAR(6);