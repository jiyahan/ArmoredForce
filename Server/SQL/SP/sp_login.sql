DELIMITER $$


/*
 * 角色注册
 */
USE account_db $$
DROP PROCEDURE IF EXISTS `account_db`.`sp_login` $$
CREATE PROCEDURE `account_db`.`sp_login` 
(
    IN name varchar(32),
    IN passwd char(32)
)
BEGIN
    DECLARE user_count INT DEFAULT 0;

    SET user_count = (SELECT COUNT(*) FROM account_info 
        WHERE account=name and password=passwd);
    IF user_count == 0 THEN
        SELECT 0 AS result; /* 帐号或密码不匹配 */
    ELSE
        SELECT 1 AS result;
    END IF;    
END 
$$

DELIMITER ;



