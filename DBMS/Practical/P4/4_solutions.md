# Practical 4 — Solutions

All queries use the shared `dbms_lab` schema from `../schema.sql` (MySQL).

---

## Aggregate Functions

### Q1. Display the total number of students in the database.

```sql
SELECT COUNT(*) AS total_students
FROM students;
```

Counts every row in the students table.

### Q2. Show the average grade (assuming letter grades are mapped to numbers) for all enrollments.

```sql
SELECT AVG(CASE grade
               WHEN 'A' THEN 4
               WHEN 'B' THEN 3
               WHEN 'C' THEN 2
               WHEN 'D' THEN 1
               ELSE 0
           END) AS average_grade
FROM enrollments;
```

Maps each letter grade to a number with `CASE`, then averages the mapped values.

### Q3. Find the total number of students in each department.

```sql
SELECT d.department_name, COUNT(s.student_id) AS total_students
FROM departments d
JOIN students s ON d.department_id = s.department_id
GROUP BY d.department_id, d.department_name;
```

Joins departments to students and counts students per department.

### Q4. Display the maximum number of credits assigned to any course.

```sql
SELECT MAX(credits) AS max_credits
FROM courses;
```

Returns the largest credit value in the courses table.

### Q5. Count how many courses are offered by each faculty member.

```sql
SELECT faculty_id, COUNT(course_id) AS course_count
FROM course_faculty
GROUP BY faculty_id;
```

Counts course assignments per faculty member.

### Q6. Show the minimum student ID in the students table.

```sql
SELECT MIN(student_id) AS min_student_id
FROM students;
```

Returns the smallest student ID present.

---

## Single Row Functions

### Q7. Display the names of all students in uppercase.

```sql
SELECT UPPER(name) AS student_name_upper
FROM students;
```

Converts each student name to uppercase with `UPPER()`.

### Q8. Show the length of each course name.

```sql
SELECT course_name, LENGTH(course_name) AS name_length
FROM courses;
```

Returns the character count of each course name with `LENGTH()`.

### Q9. Display the first 3 characters of each department name.

```sql
SELECT department_name, SUBSTRING(department_name, 1, 3) AS short_name
FROM departments;
```

Extracts the first three characters of every department name.

### Q10. Show the current date and time using MySQL function.

```sql
SELECT NOW() AS current_datetime;
```

Returns the current date and time in one value.

### Q11. Display the email domain (portion after @) of each student.

```sql
SELECT name, SUBSTRING(email, LOCATE('@', email) + 1) AS email_domain
FROM students;
```

Finds the `@` position with `LOCATE` and takes the substring after it.

### Q12. Show the name of each student along with their name reversed.

```sql
SELECT name, REVERSE(name) AS reversed_name
FROM students;
```

Uses `REVERSE()` to print each name backwards.

---

## GROUP BY Clause

### Q13. Group students by department and display the count of students in each.

```sql
SELECT department_id, COUNT(*) AS student_count
FROM students
GROUP BY department_id;
```

Groups student rows by department and counts them.

### Q14. Group courses by credit value and count how many courses fall under each credit.

```sql
SELECT credits, COUNT(*) AS course_count
FROM courses
GROUP BY credits;
```

Bunches courses by credit value and counts each bunch.

### Q15. Group faculty by department and display the number of faculty members per department.

```sql
SELECT department_id, COUNT(*) AS faculty_count
FROM faculty
GROUP BY department_id;
```

Groups faculty rows by department and counts them.

### Q16. Show total number of enrollments per course.

```sql
SELECT course_id, COUNT(*) AS enrollment_count
FROM enrollments
GROUP BY course_id;
```

Counts enrollment rows for each course.

### Q17. Display the average student ID (numerically) per department.

```sql
SELECT department_id, AVG(student_id) AS average_student_id
FROM students
GROUP BY department_id;
```

Averages the numeric student ID within each department.

---

## HAVING Clause

### Q18. Display departments with more than 3 students.

```sql
SELECT department_id, COUNT(*) AS student_count
FROM students
GROUP BY department_id
HAVING COUNT(*) > 3;
```

Groups students by department and keeps only groups larger than three.

### Q19. List faculty members who are assigned more than 2 courses.

```sql
SELECT faculty_id, COUNT(course_id) AS course_count
FROM course_faculty
GROUP BY faculty_id
HAVING COUNT(course_id) > 2;
```

Groups course assignments by faculty and keeps those with more than two.
