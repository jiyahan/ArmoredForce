


-- ----------------------------------------------------------------------------
-- sp_register_user.sql
-- Jan 14, 2014 
-- 角色注册存储过程
-- ----------------------------------------------------------------------------
DELIMITER $$
USE account_db $$
DROP PROCEDURE IF EXISTS `account_db`.`sp_login` $$
CREATE PROCEDURE `account_db`.`sp_login` 
(
    IN `account` varchar(32),
    IN `login_ip` varchar(40)
)
BEGIN
    DECLARE `pwd` char(64) DEFAULT NULL;
    DECLARE `salt` char(16) DEFAULT NULL;
    SELECT passwd, salt into `pwd`, `salt` FROM account_info WHERE account=`account`;    
    IF `pwd` == NULL or `salt` == NULL THEN
        SELECT 1 AS result;     /* 角色不存在 */
    END IF;
    
    SELECT 0 AS result, `pwd` as passwd, `salt` as salt;
END 
$$

DELIMITER ;



