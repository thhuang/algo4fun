# Write your MySQL query statement below

SELECT p.product_name, s.year, s.price
FROM Sales s
JOIN Product p on p.product_id = s.product_id;
