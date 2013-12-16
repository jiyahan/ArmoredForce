DELIMITER $$


/*
 * Ω«…´◊¢≤·
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
        SELECT 0 AS result; /* ’ ∫≈ªÚ√‹¬Î≤ª∆•≈‰ */
    ELSE
        SELECT 1 AS result;
    END IF;    
END 
$$

DELIMITER ;



