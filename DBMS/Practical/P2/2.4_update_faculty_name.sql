-- Practical 2.4: Change the name of the faculty with faculty ID 302 to "Prof. Mehul Desai".
-- Approach: UPDATE name for the matching faculty row.

UPDATE faculty
SET name = 'Prof. Mehul Desai'
WHERE faculty_id = 302;