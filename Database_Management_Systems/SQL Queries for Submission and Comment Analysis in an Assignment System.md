Section 1: Count of Submissions per Assignment

Title: Count of Submissions per Assignment

SQL query:

```sql
SELECT in_assignment AS Assignment_ID, COUNT(*) AS No_of_submission 
FROM Submissions 
GROUP BY in_assignment;
```

Description: This query calculates the count of submissions for each assignment. It selects the Assignment_ID (in_assignment column) from the Submissions table and uses the COUNT(*) function to count the number of submissions for each assignment. The result is grouped by the in_assignment column.

Section 2: Comments on a Specific Submission

Title: Comments on a Specific Submission

SQL query:

```sql
SELECT u.user_name, a.title 
FROM Comments c  
INNER JOIN DiUsers u ON c.by_user = u.user_id 
INNER JOIN Submissions s ON c.in_submission = s.id 
INNER JOIN Assignments a ON s.in_assignment = a.id  
WHERE c.in_submission = 1;
```

Description: This query retrieves the user names and assignment titles for comments made on a specific submission. It joins the Comments table with the DiUsers table on the by_user column, the Submissions table on the in_submission column, and the Assignments table on the in_assignment column. The WHERE clause filters the results for comments related to the submission with ID 1.

Section 3: Comments and Assignment Details for a Specific Submission

Title: Comments and Assignment Details for a Specific Submission

SQL query:

```sql
SELECT u.user_name AS comment_by, a.title AS assignment_title 
FROM Comments c  
INNER JOIN DiUsers u ON c.by_user = u.user_id 
INNER JOIN Submissions s ON c.in_submission = s.id 
INNER JOIN Assignments a ON s.in_assignment = a.id  
WHERE c.in_submission = 1;
```

Description: This query retrieves the user names of commenters and the assignment titles for a specific submission. It joins the Comments table with the DiUsers table on the by_user column, the Submissions table on the in_submission column, and the Assignments table on the in_assignment column. The WHERE clause filters the results for comments related to the submission with ID 1. The result includes two columns: comment_by (user name) and assignment_title.

Note: The section and query descriptions above provide an overview of each query's purpose and how they are structured.
