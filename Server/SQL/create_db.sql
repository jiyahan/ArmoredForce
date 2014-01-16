-- ----------------------------------------------------------------------------
-- create_db.sql
-- Jan 14, 2014 
-- 创建数据库和表
-- ----------------------------------------------------------------------------

delimiter $$

/* 
 * 
 * 帐号数据库 
 *
 */
CREATE DATABASE IF NOT EXISTS `account_db` $$
USE `account_db` $$

/* 账号表 */
DROP TABLE `account_info` $$
CREATE TABLE `account_info` (
  `id` int(10) unsigned AUTO_INCREMENT NOT NULL ,
  `account` varchar(32) NOT NULL,
  `reg_type` tinyint(4) NOT NULL,
  `reg_time` datetime NOT NULL,
  `reg_ip` varchar(40) NOT NULL,
  `passwd` char(64) NOT NULL,
  `salt` char(16) NOT NULL,
  `email` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `account_UNIQUE` (`account`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 $$

ALTER TABLE account_info AUTO_INCREMENT=1000 $$

/* 登录历史 */
DROP TABLE `login_history` $$
CREATE TABLE `login_history` (
  `logid` int(11) NOT NULL AUTO_INCREMENT,
  `account` varchar(32) NOT NULL,
  `login_date` datetime NOT NULL,
  `login_ip` varchar(20) NOT NULL,
  `login_status` tinyint(4) NOT NULL,
  PRIMARY KEY (`logid`),
  UNIQUE KEY `account_UNIQUE` (`account`),
  UNIQUE KEY `logid_UNIQUE` (`logid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 $$

ALTER TABLE logid AUTO_INCREMENT=10000 $$



/*
 * 
 * 游戏数据库 
 *
 */
CREATE DATABASE IF NOT EXISTS `game_db` $$
USE `game_db` $$


/* 角色信息 */
CREATE TABLE `player_base` (
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
