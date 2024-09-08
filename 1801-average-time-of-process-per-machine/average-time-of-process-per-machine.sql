# Write your MySQL query statement below

SELECT
    a1.machine_id, 
    round(avg(a2.timestamp - a1.timestamp), 3) as processing_time
FROM
    Activity a1 JOIN Activity a2
    ON 
        a1.machine_id = a2.machine_id and
        a1.process_id = a2.process_id and
        a1.activity_type like 'start'and
        a2.activity_type like 'end'
GROUP BY
    machine_id