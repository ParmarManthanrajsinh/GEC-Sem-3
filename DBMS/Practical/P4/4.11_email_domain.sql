-- Practical 4.11: Display the email domain (portion after @) of each student.
-- Approach: Use SUBSTRING with LOCATE('@', email) to take everything after the @.

SELECT name, SUBSTRING(email, LOCATE('@', email) + 1) AS email_domain
FROM students;
