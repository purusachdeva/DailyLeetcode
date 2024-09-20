# Write your MySQL query statement below

SELECT
    p.product_id,
    IFNULL(ROUND(SUM(p.price * u.units) / SUM(u.units), 2), 0) as average_price
FROM
    Prices p
LEFT JOIN
    UnitsSold u ON p.product_id = u.product_id
WHERE 
    u.purchase_date <= p.end_date 
    AND 
    p.start_date <= u.purchase_date
    OR 
    u.purchase_date is NULL
GROUP BY
    p.product_id

