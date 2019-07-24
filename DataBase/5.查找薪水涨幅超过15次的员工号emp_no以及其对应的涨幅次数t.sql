-- 查找薪水涨幅超过15次的员工号emp_no以及其对应的涨幅次数t
-- CREATE TABLE `salaries` (
--     `emp_no` int(11) NOT NULL,
--     `salary` int(11) NOT NULL,
--     `from_date` date NOT NULL,
--     `to_date` date NOT NULL,
--     PRIMARY KEY (`emp_no`,`from_date`)
-- );
-- 这个表主要记载了哪个时间段某个人的工资是多少

SELECT emp_no, COUNT(*) AS t FROM salaries group by emp_no HAVING t > 15;
