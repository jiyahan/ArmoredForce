delimiter $$

/* 帐号数据库 */
CREATE DATABASE IF NOT EXISTS `account_db` $$
USE `account_db` $$

/* 帐号表 */
CREATE TABLE `account_info` (
  `index` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `account` varchar(32) NOT NULL,
  `reg_type` tinyint(4) NOT NULL,
  `reg_time` datetime NOT NULL,
  `email` varchar(45) DEFAULT NULL,
  `password` char(32) NOT NULL COMMENT 'PBKDF2',
  `salt` char(8) NOT NULL,
  `last_login_date` datetime NOT NULL,
  `last_login_ip` varchar(40) NOT NULL,
  PRIMARY KEY (`index`),
  UNIQUE KEY `account_UNIQUE` (`account`),
  UNIQUE KEY `index_UNIQUE` (`index`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;



/* 游戏数据库 */
CREATE DATABASE IF NOT EXISTS `game_db` $$
USE `game_db` $$


/* 角色信息 */
CREATE TABLE `player_info` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) NOT NULL,
  `level` smallint(5) unsigned zerofill NOT NULL,
  `exp` bigint(20) unsigned zerofill NOT NULL COMMENT '经验',
  `rank` smallint(5) unsigned zerofill NOT NULL COMMENT '军衔',
  `gold` bigint(20) unsigned zerofill NOT NULL COMMENT '金钱',
  `action_point` int(11) unsigned zerofill NOT NULL COMMENT '行动力',
  `gems` int(11) unsigned zerofill NOT NULL COMMENT '钻石',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `name_UNIQUE` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8
$$

/* 日志数据库 */ 
CREATE DATABASE IF NOT EXISTS `log_db` $$
USE `log_db` $$

delimiter ;
