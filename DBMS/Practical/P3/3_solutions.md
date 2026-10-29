# Practical 3 — Solutions

All queries use the shared `dbms_lab` schema from `../schema.sql` (MySQL).

---

## INNER JOIN

### Q1. Display student names along with their department names.

```sql
SELECT s.name AS student_name, d.department_name
FROM students s
JOIN departments d ON s.department_id = d.department_id;
```

Joins each student to the department they belong to.

### Q2. Display faculty names with the names of their departments.

```sql
SELECT f.name AS faculty_name, d.department_name
FROM faculty f
JOIN departments d ON f.department_id = d.department_id;
```

Pairs every faculty member with their department name.

### Q3. Show student names and the course IDs they are enrolled in.

```sql
SELECT s.name AS student_name, e.course_id
FROM students s
JOIN enrollments e ON s.student_id = e.student_id;
```

Matches students to their enrollment rows to list course IDs.

### Q4. Display course names with their corresponding department IDs.

```sql
SELECT c.course_name, f.department_id
FROM courses c
JOIN course_faculty cf ON c.course_id = cf.course_id
JOIN faculty f ON cf.faculty_id = f.faculty_id;
```

Courses carry no department, so the department is taken from the faculty teaching the course.

### Q5. Show course names and the names of faculty members who teach them.

```sql
SELECT c.course_name, f.name AS faculty_name
FROM courses c
JOIN course_faculty cf ON c.course_id = cf.course_id
JOIN faculty f ON cf.faculty_id = f.faculty_id;
```

Uses the `course_faculty` bridge to pair each course with its faculty.

### Q6. List faculty names and the course IDs they are assigned to.

```sql
SELECT f.name AS faculty_name, cf.course_id
FROM faculty f
JOIN course_faculty cf ON f.faculty_id = cf.faculty_id;
```

Lists each faculty member alongside the course IDs they handle.

### Q7. Show student names and their grades for the courses they are enrolled in.

```sql
SELECT s.name AS student_name, e.grade
FROM students s
JOIN enrollments e ON s.student_id = e.student_id;
```

Retrieves each student's grades from the enrollments table.

### Q8. Display course names and the student IDs of enrolled students.

```sql
SELECT c.course_name, e.student_id
FROM courses c
JOIN enrollments e ON c.course_id = e.course_id;
```

Pairs every course with the student IDs enrolled in it.

### Q9. Show student IDs along with their department names.

```sql
SELECT s.student_id, d.department_name
FROM students s
JOIN departments d ON s.department_id = d.department_id;
```

Maps each student ID to the name of their department.

### Q10. Show faculty IDs and the names of the departments they belong to.

```sql
SELECT f.faculty_id, d.department_name
FROM faculty f
JOIN departments d ON f.department_id = d.department_id;
```

Maps each faculty ID to their department name.

### Q11. Display course names along with the department names they are part of.

```sql
SELECT c.course_name, d.department_name
FROM courses c
JOIN course_faculty cf ON c.course_id = cf.course_id
JOIN faculty f ON cf.faculty_id = f.faculty_id
JOIN departments d ON f.department_id = d.department_id;
```

Chains courses → course_faculty → faculty → departments to reach the department name.

### Q12. List student names with the course names they are enrolled in.

```sql
SELECT s.name AS student_name, c.course_name
FROM students s
JOIN enrollments e ON s.student_id = e.student_id
JOIN courses c ON e.course_id = c.course_id;
```

Joins students to courses through the enrollments table.

### Q13. Show faculty names and the names of courses they are teaching.

```sql
SELECT f.name AS faculty_name, c.course_name
FROM faculty f
JOIN course_faculty cf ON f.faculty_id = cf.faculty_id
JOIN courses c ON cf.course_id = c.course_id;
```

Joins faculty to courses through the `course_faculty` table.

### Q14. Display student names along with the grades they received.

```sql
SELECT s.name AS student_name, e.grade
FROM students s
JOIN enrollments e ON s.student_id = e.student_id;
```

Returns every student name with the grade recorded for each enrollment.

### Q15. List course names with faculty IDs teaching those courses.

```sql
SELECT c.course_name, cf.faculty_id
FROM courses c
JOIN course_faculty cf ON c.course_id = cf.course_id;
```

Pairs each course with the faculty IDs assigned to it.

---

## Other JOINs

### Q16. LEFT JOIN: List all students with their enrolled course IDs (if any).

```sql
SELECT s.name AS student_name, e.course_id
FROM students s
LEFT JOIN enrollments e ON s.student_id = e.student_id;
```

Keeps every student, showing NULL for those with no enrollment.

### Q17. LEFT JOIN: Show all courses along with their assigned faculty IDs (if any).

```sql
SELECT c.course_name, cf.faculty_id
FROM courses c
LEFT JOIN course_faculty cf ON c.course_id = cf.course_id;
```

Keeps every course, showing NULL for courses without assigned faculty.

### Q18. RIGHT JOIN: Display all departments with the names of faculty in each (if any).

```sql
SELECT d.department_name, f.name AS faculty_name
FROM faculty f
RIGHT JOIN departments d ON f.department_id = d.department_id;
```

Keeps every department, showing NULL for departments with no faculty.

### Q19. LEFT JOIN: Show all faculty names with the course IDs they are teaching (if any).

```sql
SELECT f.name AS faculty_name, cf.course_id
FROM faculty f
LEFT JOIN course_faculty cf ON f.faculty_id = cf.faculty_id;
```

Keeps every faculty member, showing NULL for those teaching no course.

### Q20. SELF JOIN: List pairs of students who belong to the same department.

```sql
SELECT s1.name AS student_1, s2.name AS student_2, s1.department_id
FROM students s1
JOIN students s2
  ON s1.department_id = s2.department_id
 AND s1.student_id < s2.student_id;
```

Self-joins students on equal department, using `<` to emit each pair once.
