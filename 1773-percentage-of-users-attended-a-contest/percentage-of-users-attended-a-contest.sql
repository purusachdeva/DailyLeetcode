# Write your MySQL query statement below

SELECT contest_id, 
ROUND(COUNT(contest_id)/(SELECT COUNT(user_id) from Users) * 100, 2) as percentage
from Register
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC;