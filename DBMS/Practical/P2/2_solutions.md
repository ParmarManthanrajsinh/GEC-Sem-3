# Practical 2 — Solutions

All queries use the shared `dbms_lab` schema from `../schema.sql` (MySQL).

---

## Update Queries

### Q1. Update the email address of the student with student ID 101 to alice.shah@college.edu.

```sql
UPDATE students
SET email = 'alice.shah@college.edu'
WHERE student_id = 101;
```

Sets the email of the one matching student row.

### Q2. Update all students from department ID 3 to department ID 2.

```sql
UPDATE students
SET department_id = 2
WHERE department_id = 3;
```

Reassigns every student currently in department 3 to department 2.

### Q3. Change the number of credits for the course "Database Systems" to 5.

```sql
UPDATE courses
SET credits = 5
WHERE course_name = 'Database Systems';
```

Updates the credits of the course matched by name.

### Q4. Change the name of the faculty with faculty ID 302 to "Prof. Mehul Desai".

```sql
UPDATE faculty
SET name = 'Prof. Mehul Desai'
WHERE faculty_id = 302;
```

Renames the faculty member with ID 302.

### Q5. Update all enrollments where grade is 'C' and change it to 'B'.

```sql
UPDATE enrollments
SET grade = 'B'
WHERE grade = 'C';
```

Promotes every 'C' grade to 'B' in the enrollments table.

---

## ALTER TABLE – Add, Modify, Drop Column

### Q6. Add a new column phone of type VARCHAR(15) to the students table.

```sql
ALTER TABLE students
ADD COLUMN phone VARCHAR(15);
```

Adds the `phone` column with a 15-character limit.

### Q7. Modify the phone column in the students table to restrict it to VARCHAR(10).

```sql
ALTER TABLE students
MODIFY COLUMN phone VARCHAR(10);
```

Narrows the `phone` column to 10 characters.

### Q8. Remove the phone column from the students table.

```sql
ALTER TABLE students
DROP COLUMN phone;
```

Drops the `phone` column entirely.

### Q9. Add a column gender of type CHAR(1) to the faculty table.

```sql
ALTER TABLE faculty
ADD COLUMN gender CHAR(1);
```

Adds a single-character `gender` column to faculty.

### Q10. Modify the gender column in the faculty table to be VARCHAR(6) to store values like "Male" or "Female".

```sql
ALTER TABLE faculty
MODIFY COLUMN gender VARCHAR(6);
```

Widens `gender` to hold full words such as "Male"/"Female".

### Q11. Remove the gender column from the faculty table.

```sql
ALTER TABLE faculty
DROP COLUMN gender;
```

Drops the `gender` column.

---

## ALTER TABLE – With Defaults and Constraints

### Q12. Add a new column semester (INT) to the courses table.

```sql
ALTER TABLE courses
ADD COLUMN semester INT;
```

Adds an integer `semester` column to courses.

### Q13. Modify the semester column to set its default value to 4.

```sql
ALTER TABLE courses
MODIFY COLUMN semester INT DEFAULT 4;
```

Makes the default value of `semester` equal to 4.

### Q14. Remove the semester column from the courses table.

```sql
ALTER TABLE courses
DROP COLUMN semester;
```

Drops the `semester` column.

### Q15. Modify the name column in the students table to ensure it cannot be NULL.

```sql
ALTER TABLE students
MODIFY COLUMN name VARCHAR(100) NOT NULL;
```

Adds a `NOT NULL` constraint on `students.name`. *(Note: sample row 121 has a NULL name, so update/remove that row first if the server rejects the change.)*

---

## Create and ALTER TABLE – Primary Key and Foreign Key

### Q16. Create test_enrollments with columns enroll_id, student_id, course_id, then add a primary key on enroll_id and foreign keys on student_id and course_id.

```sql
CREATE TABLE test_enrollments (
    enroll_id INT,
    student_id INT,
    course_id INT
);

ALTER TABLE test_enrollments
ADD PRIMARY KEY (enroll_id);

ALTER TABLE test_enrollments
ADD FOREIGN KEY (student_id) REFERENCES students(student_id);

ALTER TABLE test_enrollments
ADD FOREIGN KEY (course_id) REFERENCES courses(course_id);
```

Creates the table and adds the primary key plus both referential constraints.

---

## Delete Queries

### Q17. Create a new table named test_enrollments with columns enroll_id, student_id, and course_id.

```sql
CREATE TABLE IF NOT EXISTS test_enrollments (
    enroll_id INT,
    student_id INT,
    course_id INT
);
```

Creates the helper table for the delete exercises (`IF NOT EXISTS` keeps it runnable after Q16).

### Q18. Delete the enrollment record with enrollment ID 20.

```sql
DELETE FROM test_enrollments
WHERE enroll_id = 20;
```

Removes the enrollment row whose ID is 20.

### Q19. Delete all students who belong to course_ID 9.

```sql
DELETE FROM test_enrollments
WHERE course_id = 9;
```

Deletes every enrollment row linking a student to course 9.

### Q20. Delete all faculty members who belong to Course_ID 3.

```sql
DELETE FROM course_faculty
WHERE course_id = 3;
```

Removes the faculty-to-course mappings for course 3 (faculty have no `course_id` column of their own).

### Q21. Delete all students whose course id is not specified (NULL).

```sql
DELETE FROM test_enrollments
WHERE course_id IS NULL;
```

Deletes rows where no course has been assigned.

### Q22. Delete all courses having student_id=1.

```sql
DELETE FROM test_enrollments
WHERE student_id = 1;
```

Removes every course enrollment belonging to student 1.

---

## Truncate Table Query

### Q23. Remove all records from the test_enrollments table without deleting the table structure.

```sql
TRUNCATE TABLE test_enrollments;
```

Empties the table while preserving its structure.

---

## Drop Table Query

### Q24. Drop the table test_enrollments if it exists.

```sql
DROP TABLE IF EXISTS test_enrollments;
```

Removes the table and its structure without error if it is missing.