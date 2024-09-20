# Write your MySQL query statement below

SELECT
    ROUND(SUM(if(order_date = customer_pref_delivery_date, 1, 0)) / COUNT(*) * 100, 2) as immediate_percentage
FROM
    Delivery
WHERE
    (customer_id, order_date) in (
        SELECT customer_id, min(order_date)
        FROM DELIVERY
        GROUP BY CUSTOMER_ID
    )
