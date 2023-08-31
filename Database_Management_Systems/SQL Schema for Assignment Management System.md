The following SQL statements create the necessary tables for an Assignment Management System. The tables include Departments, DiUsers (Users), Pages, Assignments, Submissions, and Comments. These tables establish relationships through foreign keys and ensure data integrity. Additionally, a trigger named "new_department_confirm" is defined to execute actions before inserting data into the Departments table.

SQL Schema:

Table: Departments

```sql
CREATE TABLE Departments(
    department_code VARCHAR(64) NOT NULL PRIMARY KEY,
    department_name VARCHAR(256) NOT NULL
);
```

Trigger: new_department_confirm

```sql
CREATE OR REPLACE TRIGGER new_department_confirm
BEFORE INSERT ON Departments
FOR EACH ROW
BEGIN
    dbms_output.put_line('Created new department ' || UPPER(TRIM(:NEW.department_code)));
    dbms_output.put_line('Name: ' || INITCAP(TRIM(:NEW.department_name)));
END;
/
```

Table: DiUsers (Users)

```sql
CREATE TABLE DiUsers(
    user_id INT NOT NULL PRIMARY KEY,
    user_name VARCHAR(512) NOT NULL,
    user_email VARCHAR(256) NULL UNIQUE,
    user_password VARCHAR(512) NOT NULL,
    user_department VARCHAR(64) NOT NULL,
    is_superuser CHAR(1) DEFAULT 'N' NOT NULL,
    is_student CHAR(1) DEFAULT 'Y' NOT NULL,
    is_teacher CHAR(1) DEFAULT 'N' NOT NULL,
    CONSTRAINT user_department_fk FOREIGN KEY(user_department)
        REFERENCES Departments(department_code) ON DELETE CASCADE
);
```

Table: Pages

```sql
CREATE TABLE Pages(
    page_code VARCHAR(128) NOT NULL PRIMARY KEY,
    page_name VARCHAR(512) NOT NULL,
    page_department VARCHAR(64) NOT NULL,
    CONSTRAINT page_department_fk FOREIGN KEY(page_department)
        REFERENCES Departments(department_code) ON DELETE CASCADE
);
```

Table: Assignments

```sql
CREATE TABLE Assignments(
    id INT NOT NULL PRIMARY KEY,
    in_page VARCHAR(128) NOT NULL,
    by_teacher INT NOT NULL,
    title VARCHAR(512) NOT NULL,
    description VARCHAR(1024) NOT NULL,
    instructions CLOB NULL,
    template CLOB NULL,
    passing_points INT DEFAULT 35 NOT NULL,
    maximum_points INT DEFAULT 100 NOT NULL,
    allow_submission CHAR(1) DEFAULT 'Y' NOT NULL,
    allow_comments CHAR(1) DEFAULT 'Y' NOT NULL,
    CONSTRAINT in_page_fk FOREIGN KEY(in_page)
        REFERENCES Pages(page_code) ON DELETE CASCADE,
    CONSTRAINT by_teacher_fk FOREIGN KEY(by_teacher)
        REFERENCES DiUsers(user_id) ON DELETE CASCADE
);
```

Table: Submissions

```sql
CREATE TABLE Submissions(
    id INT NOT NULL PRIMARY KEY,
    in_assignment INT NOT NULL,
    by_user INT NOT NULL,
    solution CLOB NULL,
    remark VARCHAR(1024) NULL,
    points INT DEFAULT 35 NOT NULL,
    CONSTRAINT in_assignment_fk FOREIGN KEY(in_assignment)
        REFERENCES Assignments(id) ON DELETE CASCADE,
    CONSTRAINT by_user_fk FOREIGN KEY(by_user)
        REFERENCES DiUsers(user_id) ON DELETE CASCADE
);
```

Table: Comments

```sql
CREATE TABLE Comments(
    in_submission INT NOT NULL,
    by_user INT NOT NULL,
    theme VARCHAR(1024) NULL,
    content CLOB NULL,
    CONSTRAINT in_submission_fk FOREIGN KEY(in_submission)
        REFERENCES Submissions(id) ON DELETE CASCADE,
    CONSTRAINT comment_by_user_fk FOREIGN KEY(by_user)
        REFERENCES DiUsers(user_id) ON DELETE CASCADE
);
```

Note: The SQL schema provided above creates the necessary tables and relationships for an Assignment Management System. It ensures referential integrity and enables
