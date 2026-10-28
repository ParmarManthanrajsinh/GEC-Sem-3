-- DBMS Lab Manual (BE03000091) - Shared schema and sample data
-- Used by all experiments. MySQL syntax.
-- Run once before attempting any practical.

CREATE DATABASE IF NOT EXISTS dbms_lab;
USE dbms_lab;

DROP TABLE IF EXISTS enrollments;
DROP TABLE IF EXISTS course_faculty;
DROP TABLE IF EXISTS students;
DROP TABLE IF EXISTS faculty;
DROP TABLE IF EXISTS courses;
DROP TABLE IF EXISTS departments;

CREATE TABLE departments (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(100)
);

CREATE TABLE students (
    student_id INT PRIMARY KEY,
    name VARCHAR(100),
    dob DATE,
    email VARCHAR(100),
    department_id INT,
    FOREIGN KEY (department_id) REFERENCES departments(department_id)
);

CREATE TABLE courses (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(100),
    credits INT
);

CREATE TABLE faculty (
    faculty_id INT PRIMARY KEY,
    name VARCHAR(100),
    email VARCHAR(100),
    department_id INT,
    FOREIGN KEY (department_id) REFERENCES departments(department_id)
);

CREATE TABLE course_faculty (
    course_id INT,
    faculty_id INT,
    semester INT,
    PRIMARY KEY (course_id, faculty_id),
    FOREIGN KEY (course_id) REFERENCES courses(course_id),
    FOREIGN KEY (faculty_id) REFERENCES faculty(faculty_id)
);

CREATE TABLE enrollments (
    enrollment_id INT PRIMARY KEY,
    student_id INT,
    course_id INT,
    semester INT,
    grade CHAR(1),
    FOREIGN KEY (student_id) REFERENCES students(student_id),
    FOREIGN KEY (course_id) REFERENCES courses(course_id)
);

INSERT INTO departments (department_id, department_name) VALUES
(1, 'Computer Engineering'),
(2, 'Electronics'),
(3, 'Mechanical'),
(4, 'Civil'),
(5, 'IT'),
(6, 'Chemical'),
(7, 'Instrumentation'),
(8, 'Automobile'),
(9, 'Textile'),
(10, 'Environmental'),
(11, 'Mechatronics'),
(12, 'Aerospace'),
(13, 'Mining'),
(14, 'Biomedical'),
(15, 'Petroleum'),
(16, 'Robotics'),
(17, 'Agricultural'),
(18, 'Architecture'),
(19, 'Marine'),
(20, 'Nanotechnology');

INSERT INTO students (student_id, name, dob, email, department_id) VALUES
(101, 'Khushi Shah', '2004-05-10', 'alice@example.com', 1),
(102, 'Bhavesh Patel', '2003-11-23', 'bhavesh@example.com', 1),
(103, 'Chirag Mehta', '2004-01-15', 'chirag@example.com', 2),
(104, 'Dhruvi Joshi', '2003-06-08', 'dhruvi@example.com', 3),
(105, 'Esha Trivedi', '2004-09-14', 'esha@example.com', 1),
(106, 'Farhan Shaikh', '2003-12-20', 'farhan@example.com', 2),
(107, 'Gaurav Rana', '2004-03-12', 'gaurav@example.com', 3),
(108, 'Heena Patel', '2004-08-30', 'heena@example.com', 1),
(109, 'Isha Desai', '2004-07-01', 'isha@example.com', 2),
(110, 'Jay Solanki', '2003-04-25', 'jay@example.com', 3),
(111, 'Kajal Vyas', '2004-11-05', 'kajal@example.com', 1),
(112, 'Laksh Soni', '2003-10-18', 'laksh@example.com', 1),
(113, 'Manav Panchal', '2004-01-22', 'manav@example.com', 2),
(114, 'Neha Gohil', '2003-03-19', 'neha@example.com', 2),
(115, 'Om Thakkar', '2004-02-28', 'om@example.com', 3),
(116, 'Pooja Zala', '2004-07-17', 'pooja@example.com', 1),
(117, 'Ravi Chauhan', '2003-12-12', 'ravi@example.com', 2),
(118, 'Sneha Rawal', '2004-06-16', 'sneha@example.com', 3),
(119, 'Tanvi Shah', '2004-10-02', 'tanvi@example.com', 1),
(120, 'Utsav Dave', '2003-09-09', 'utsav@example.com', 3),
(121, NULL, '2000-12-01', NULL, 2);

INSERT INTO courses (course_id, course_name, credits) VALUES
(201, 'Database Systems', 4),
(202, 'Operating Systems', 3),
(203, 'Microprocessors', 3),
(204, 'Computer Networks', 4),
(205, 'Data Structures', 4),
(206, 'Software Engineering', 3),
(207, 'Web Development', 3),
(208, 'Machine Learning', 4),
(209, 'Compiler Design', 4),
(210, 'Cloud Computing', 3),
(211, 'Cyber Security', 3),
(212, 'IoT', 3),
(213, 'AI Fundamentals', 4),
(214, 'DBMS Lab', 2),
(215, 'Operating Systems Lab', 2),
(216, 'DS Lab', 2),
(217, 'Project Phase 1', 2),
(218, 'Project Phase 2', 2),
(219, 'Python Programming', 4),
(220, 'C Programming', 4),
(221, 'DBMS Lab', 2),
(222, NULL, 3),
(223, 'DBMS Lab', 3),
(224, 'IOT Lab', NULL);

INSERT INTO faculty (faculty_id, name, email, department_id) VALUES
(301, 'Prof. Kiran', 'kiran@college.edu', 1),
(302, 'Prof. Mehul', 'mehul@college.edu', 2),
(303, 'Prof. Rina', 'rina@college.edu', 1),
(304, 'Prof. Tejas', 'tejas@college.edu', 1),
(305, 'Prof. Dhara', 'dhara@college.edu', 3),
(306, 'Prof. Nirav', 'nirav@college.edu', 1),
(307, 'Prof. Mitali', 'mitali@college.edu', 2),
(308, 'Prof. Arjun', 'arjun@college.edu', 3),
(309, 'Prof. Bharti', 'bharti@college.edu', 2),
(310, 'Prof. Harsh', 'harsh@college.edu', 1),
(311, 'Prof. Zarna', 'zarna@college.edu', 3),
(312, 'Prof. Kamal', 'kamal@college.edu', 1),
(313, 'Prof. Harita', 'harita@college.edu', 2),
(314, 'Prof. Suresh', 'suresh@college.edu', 3),
(315, 'Prof. Reema', 'reema@college.edu', 1),
(316, 'Prof. Ankit', 'ankit@college.edu', 2),
(317, 'Prof. Seema', 'seema@college.edu', 1),
(318, 'Prof. Viraj', 'viraj@college.edu', 3),
(319, 'Prof. Hetal', 'hetal@college.edu', 1),
(320, 'Prof. Shweta', 'shweta@college.edu', 1);

INSERT INTO course_faculty (course_id, faculty_id, semester) VALUES
(201, 301, 4),
(202, 301, 4),
(203, 302, 4),
(204, 303, 5),
(205, 304, 3),
(206, 305, 3),
(207, 306, 4),
(208, 307, 6),
(209, 308, 5),
(210, 309, 6),
(211, 310, 5),
(212, 311, 5),
(213, 312, 6),
(214, 313, 4),
(215, 314, 4),
(216, 315, 3),
(217, 316, 7),
(218, 317, 5),
(219, 318, 3),
(220, 319, 2);

INSERT INTO enrollments (enrollment_id, student_id, course_id, semester, grade) VALUES
(1, 101, 201, 4, 'A'),
(2, 101, 202, 4, 'B'),
(3, 102, 201, 4, 'A'),
(4, 103, 203, 4, 'C'),
(5, 104, 202, 4, 'B'),
(6, 105, 201, 4, 'A'),
(7, 106, 205, 3, 'B'),
(8, 107, 204, 5, 'B'),
(9, 108, 204, 5, 'A'),
(10, 109, 205, 3, 'C'),
(11, 110, 206, 3, 'B'),
(12, 111, 207, 4, 'A'),
(13, 112, 208, 6, 'B'),
(14, 113, 209, 5, 'A'),
(15, 114, 210, 6, 'C'),
(16, 115, 201, 5, 'B'),
(17, 116, 212, 5, 'B'),
(18, 117, 213, 6, 'A'),
(19, 118, 214, 4, 'A'),
(20, 119, 215, 4, 'B');