delimiter $$

/* 帐号数据库 */
CREATE DATABASE IF NOT EXISTS `account_db` $$
USE `account_db` $$

/* 帐号表 */
CREATE TABLE `account_info` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `reg_type` tinyint(4) unsigned NOT NULL,
  `account` varchar(45) NOT NULL,
  `password` char(64) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `diamonds` int(11) NOT NULL COMMENT '钻石',
  PRIMARY KEY (`id`),
  UNIQUE KEY `account_UNIQUE` (`account`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8$$



/* 游戏数据库 */
CREATE DATABASE IF NOT EXISTS `game_db` $$
USE `game_db` $$

delimiter $$

/* 角色信息 */
CREATE TABLE `player_info` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) NOT NULL,
  `level` smallint(5) unsigned zerofill NOT NULL,
  `exp` bigint(20) unsigned zerofill NOT NULL COMMENT '经验',
  `rank` smallint(5) unsigned zerofill NOT NULL COMMENT '军衔',
  `gold` bigint(20) unsigned zerofill NOT NULL COMMENT '金钱',
  `action_point` int(10) unsigned zerofill NOT NULL COMMENT '行动力',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `name_UNIQUE` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8
$$

/* 日志数据库 */ 
CREATE DATABASE IF NOT EXISTS `log_db` $$
USE `log_db` $$


