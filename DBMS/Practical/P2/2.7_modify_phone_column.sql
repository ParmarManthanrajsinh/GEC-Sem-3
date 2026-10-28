-- Practical 2.7: Modify the phone column in the students table to restrict it to VARCHAR(10).
-- Approach: ALTER TABLE ... MODIFY COLUMN to change the data type length.

ALTER TABLE students
MODIFY COLUMN phone VARCHAR(10);