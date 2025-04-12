# **Context**
## INNER JOIN
- Returns only the rows that have matching values in both tables.
- If there's no match, the row is excluded from the result.
  
![image](https://github.com/user-attachments/assets/10fc48c7-5a62-4750-a404-6e9df8c0a090)

![image](https://github.com/user-attachments/assets/ac35b433-6d55-4fe2-901a-455b1d7502f1)

```mysql
  SELECT e.name, d.dept_name
  FROM employees e INNER JOIN departments d ON e.dept_id = d.dept_id;
```
**Result**
![image](https://github.com/user-attachments/assets/7d1c3c7b-08c5-4a9e-85cd-312bf2ba1442)

## LEFT JOIN (or LEFT OUTER JOIN)
- Returns all rows from the left table, and the matched rows from the right table.
- If there's no match, NULLs are returned for columns from the right table.

```mysql
  SELECT *
  FROM employees e LEFT JOIN departments d ON e.dept_id = d.id;
```
**Result**
![image](https://github.com/user-attachments/assets/cb533389-4bea-471a-88a6-a7129d0a54a5)

## RIGHT JOIN (or RIGHT OUTER JOIN)
- Opposite of LEFT JOIN: Returns all rows from the right table, and the matched rows from the left table.
- If there's no match, NULLs are returned for columns from the left table.

``` mysql
  SELECT *
  FROM employees e RIGHT JOIN departments d ON e.dept_id = d.id;
```

**Result**
![image](https://github.com/user-attachments/assets/352953ac-c8c1-485d-af71-f6eb71092043)

# Anatomy
## 175. Combine Two Tables
Table: *Person*

<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>personId</td><td>int</td></tr>
  <tr><td>lastName</td><td>varchar</td></tr>
  <tr><td>firstName</td><td>varchar</td></tr>
</table>

Table: *Address*
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>addressId</td><td>int</td></tr>
  <tr><td>personId</td><td>int</td></tr>
  <tr><td>city</td><td>varchar</td></tr>
  <tr><td>state</td><td>varchar</td></tr>
</table>

*Write a solution to report the first name, last name, city, and state of each person in the Person table. If the address of a personId is not present in the Address table, report null instead.*
```mysql
SELECT firstName, lastName, city, state
FROM Person p LEFT JOIN Address a on p.personId = a.personId;
```


## 181. Employees Earning More Than Their Managers

Table: *Employee*
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>id</td><td>int</td></tr>
  <tr><td>name</td><td>varchar</td></tr>
  <tr><td>salary</td><td>int</td></tr>
  <tr><td>managerId</td><td>int</td></tr>
</table>

*Write a solution to find the employees who earn more than their managers.*

```mysql
  SELECT e2.name Employee
  FROM Employee e1 INNER JOIN Employee e2 ON e1.id = e2.managerId
  WHERE e1.salary < e2.salary;
```
If the initial *Employee* table was like this:
![image](https://github.com/user-attachments/assets/b151ed51-030e-4592-94c4-30ca32eaaa84)

Then after **INNER JOIN** the table looks like this:
![image](https://github.com/user-attachments/assets/2e6d927b-fd5a-49e9-afe2-d29f2773fdc7)

Then all we have to do is check for the condition if *e1.salary < e2.salary* right?

## 182. Duplicate Emails

Table: *Person*

<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>id</td><td>int</td></tr>
  <tr><td>email</td><td>varchar</td></tr>
</table>

```mysql
  SELECT email
  FROM Person
  GROUP BY email
  HAVING count(email) > 1;
```
What **GROUP BY** is groups the table based on the value and performs different operations such as *COUNT(), SUM(), AVG(), MAX(), MIN()*.

*Alternaite solution for this problem can be:*
```mysql
  SELECT DISTINCT(p1.email)
  FROM Person p1, Person p2
  WHERE p1.id <> p2.id AND p1.email = p2.email;
```

This joins the two table and checks if *ids* aren't equal and email matches or not. If email matches then that mean there is another person with same email. Exactly what we were looking for.

## 183. Customers Who Never Order

Table: *Customers*
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>id</td><td>int</td></tr>
  <tr><td>name</td><td>varchar</td></tr>
</table>

Table: *Customers*
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>id</td><td>int</td></tr>
  <tr><td>customerId</td><td>int</td></tr>
</table>

*Write a solution to find all customers who never order anything.*
*Solution 1:*
```mysql
  SELECT c.name as Customers
  FROM Customers c LEFT JOIN Orders o ON c.id = o.customerId
  WHERE o.customerId IS NULL;
```
What this does if *LEFT JOINS* with *Oders* table. As a result we get a table *Customer's* table's id matching with *Oder's* table's *customerId* if there is no such row then that row will be null. But all the *Customer* table's row will be there. So the row with NULL value in the *customerId* column have to be answer.

*Solution 2:*
```mysql
  SELECT c.name as Customers
  FROM Customers c
  WHERE c.id NOT IN(
      SELECT customerId
      FROM Orders
  );
```
## 196. Delete Duplicate Emails

*Write a solution to delete all duplicate emails, keeping only one unique email with the smallest id.*
Table: *Person*
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>id</td><td>int</td></tr>
  <tr><td>email</td><td>varchar</td></tr>
</table>

*Solution 1:*
```mysql
  DELETE p1
  FROM Person p1, Person p2
  WHERE p1.email = p2.email AND p1.id > p2.id;
```

*Solution 2:*
```mysql
  DELETE
  FROM Person
  WHERE id not in (
      SELECT *
      FROM
      (SELECT MIN(id)
      FROM Person
      GROUP BY email) p
  );
```

## 197. Rising Temperature

Table: *Weather*
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>id</td><td>int</td></tr>
  <tr><td>recordDate</td><td>date</td></tr>
  <tr><td>temperature</td><td>int</td></tr>
</table>

*Write a solution to find all dates' id with higher temperatures compared to its previous dates (yesterday).*
```mysql
  SELECT cd.id
  FROM Weather as cd
  WHERE EXISTS(
      SELECT 1
      FROM Weather as pv
      WHERE pv.temperature < cd.temperature AND  cd.recordDate = pv.recordDate + INTERVAL 1 DAY
  );
```

## 511. Game Play Analysis I

Table: *Activity*
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>player_id</td><td>int</td></tr>
  <tr><td>device_id</td><td>int</td></tr>
  <tr><td>event_date</td><td>date</td></tr>
  <tr><td>games_played</td><td>int</td></tr>
</table>

*Write a solution to find the first login date for each player.*
```mysql
  SELECT player_id, MIN(event_date) as first_login
  FROM Activity
  GROUP BY player_id;
```

## 577. Employee Bonus

Table: *Employee*
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>empId</td><td>int</td></tr>
  <tr><td>name</td><td>varchar</td></tr>
  <tr><td>supervisor</td><td>int</td></tr>
  <tr><td>salary</td><td>int</td></tr>
</table>

Table: *Bonus*
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>empId</td><td>int</td></tr>
  <tr><td>bonus</td><td>int</td></tr>
</table>

*Write a solution to report the name and bonus amount of each employee with a bonus less than 1000.*

```mysql
  SELECT e.name, b.bonus
  FROM Employee e LEFT JOIN Bonus b ON e.empId = b.empId
  WHERE b.bonus < 1000 OR b.bonus IS NULL;
```
*POINTERS:* Just using *WHERE b.bonus < 1000* leaves out whoose *b.bonus* is *NULL.*

## 584. Find Customer Referee

*Table:* Customer
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>id</td><td>int</td></tr>
  <tr><td>name</td><td>varchar</td></tr>
  <tr><td>referee_id</td><td>int</td></tr>
</table>

  ```mysql
  SELECT name
  FROM Customer
  WHERE referee_id <> 2 OR referee_id IS NULL;
```
*POINTERS:* Just using *referee_id <> 2* leaves out who were not refered by any.

## 586. Customer Placing the Largest Number of Orders

*Table:* Orders
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>order_number</td><td>int</td></tr>
  <tr><td>customer_number</td><td>int</td></tr>
</table>

*Write a solution to find the customer_number for the customer who has placed the largest number of orders.*

```mysql
  SELECT customer_number
  FROM Orders 
  GROUP BY customer_number ORDER BY COUNT(order_number) DESC LIMIT 1;
```

Here, *GROUP BY customer_number ORDER BY COUNT(order_number) DESC LIMIT 1;* this groups the table based on *customer_number* then sorts it with respect to *COUNT()* in descending order.

## 595. Big Countries

*Table:* World
<table>
  <tr>
    <th style="width:300px;">Column Name</th>
    <th style="width:150px;">Type</th>
  </tr>
  <tr><td>name</td><td>varchar</td></tr>
  <tr><td>continent</td><td>varchar</td></tr>
  <tr><td>area</td><td>int</td></tr>
  <tr><td>population</td><td>int</td></tr>
  <tr><td>gdp</td><td>bigint</td></tr>
</table>

A country is big if:
- it has an area of at least three million (i.e., 3000000 km2), or
- it has a population of at least twenty-five million (i.e., 25000000).

*Write a solution to find the name, population, and area of the big countries.*
```mysql
  SELECT name, population, area
  FROM World
  WHERE area >= 3000000 OR population >= 25000000;
```
