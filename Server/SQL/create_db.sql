delimiter $$

/* �ʺ����ݿ� */
CREATE DATABASE IF NOT EXISTS `account_db` $$
USE `account_db` $$

/* �ʺű� */
CREATE TABLE `account_info` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `reg_type` tinyint(4) unsigned NOT NULL,
  `account` varchar(45) NOT NULL,
  `password` char(64) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `diamonds` int(11) NOT NULL COMMENT '��ʯ',
  PRIMARY KEY (`id`),
  UNIQUE KEY `account_UNIQUE` (`account`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8$$



/* ��Ϸ���ݿ� */
CREATE DATABASE IF NOT EXISTS `game_db` $$
USE `game_db` $$

delimiter $$

/* ��ɫ��Ϣ */
CREATE TABLE `player_info` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(45) NOT NULL,
  `level` smallint(5) unsigned zerofill NOT NULL,
  `exp` bigint(20) unsigned zerofill NOT NULL COMMENT '����',
  `rank` smallint(5) unsigned zerofill NOT NULL COMMENT '����',
  `gold` bigint(20) unsigned zerofill NOT NULL COMMENT '��Ǯ',
  `action_point` int(10) unsigned zerofill NOT NULL COMMENT '�ж���',
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `name_UNIQUE` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8
$$

/* ��־���ݿ� */ 
CREATE DATABASE IF NOT EXISTS `log_db` $$
USE `log_db` $$


