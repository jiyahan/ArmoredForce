-- ----------------------------------------------------------------------------
-- sp_register_user.sql
-- Jan 14, 2014 
-- 角色注册存储过程
-- ----------------------------------------------------------------------------

DROP PROCEDURE IF EXISTS `sp_register_user`;

DELIMITER $$
USE `account_db`$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_register_user`(
    IN `account` varchar(32),
    IN `reg_type` tinyint(4),
    IN `reg_ip` varchar(40),
    IN `pwd` char(64),
    IN `salt` char(16),
    IN `email` varchar(45)
)
BEGIN
	DECLARE is_exist INT(11) DEFAULT 0 ;
    SET is_exist = (SELECT COUNT(*) FROM account_info WHERE account=`account`) ;
    IF is_exist > 0 THEN
        SELECT 1 AS result;    
    END IF;

    INSERT INTO account_info(account, reg_type, reg_time, reg_ip, passwd, salt, email)
        VALUES(`account`, `reg_type`, now(), `reg_ip`, `pwd`, `salt`, `email`);
    SELECT 0 AS result; 
END$$

DELIMITER ;



