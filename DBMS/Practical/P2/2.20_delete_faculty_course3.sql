-- Practical 2.20: Delete all faculty members who belong to Course_ID 3.
-- Approach: course_faculty maps faculty to courses - delete the mappings for course 3.

DELETE FROM course_faculty
WHERE course_id = 3;