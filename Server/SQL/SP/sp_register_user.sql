DELIMITER $$


/*
 * 角色注册
 */
USE account_db $$
DROP PROCEDURE IF EXISTS `account_db`.`sp_register_user` $$
CREATE PROCEDURE `account_db`.`sp_register_user` 
(
    IN type tinyint,
    IN name varchar(32),
    IN passwd char(32)
)
BEGIN
    DECLARE user_count INT DEFAULT 0;
    SET user_count = (SELECT COUNT(*) FROM account_info WHERE account=name);
    IF user_count > 0 THEN
        SELECT 1 AS result;     /* 角色已存在 */
    END IF;

    INSERT INTO account_info(reg_type, account, password, diamonds)
        VALUES(type, name, passwd, 0);

    SELECT 0 AS result;
END 
$$

DELIMITER ;



