-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               11.4.3-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             12.6.0.6765
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Dumping database structure for glasstrack_db
CREATE DATABASE IF NOT EXISTS `glasstrack_db` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci */;
USE `glasstrack_db`;

-- Dumping structure for table glasstrack_db.auto
CREATE TABLE IF NOT EXISTS `auto` (
  `a_id` int(11) NOT NULL AUTO_INCREMENT,
  `a_marca` varchar(300) NOT NULL,
  `a_model` varchar(300) DEFAULT NULL,
  PRIMARY KEY (`a_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table glasstrack_db.auto: ~0 rows (approximately)

-- Dumping structure for table glasstrack_db.parbrize
CREATE TABLE IF NOT EXISTS `parbrize` (
  `p_id` int(11) NOT NULL AUTO_INCREMENT,
  `p_code` char(255) NOT NULL,
  `p_origine` char(155) DEFAULT NULL,
  `p_count` int(11) NOT NULL,
  `p_price` decimal(20,6) NOT NULL,
  PRIMARY KEY (`p_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table glasstrack_db.parbrize: ~0 rows (approximately)

-- Dumping structure for table glasstrack_db.parbrize_auto
CREATE TABLE IF NOT EXISTS `parbrize_auto` (
  `a_id` int(11) NOT NULL,
  `p_id` int(11) NOT NULL,
  KEY `auto_fk1` (`a_id`),
  KEY `parbrize_fk2` (`p_id`),
  CONSTRAINT `auto_fk1` FOREIGN KEY (`a_id`) REFERENCES `auto` (`a_id`) ON DELETE CASCADE,
  CONSTRAINT `parbrize_fk2` FOREIGN KEY (`p_id`) REFERENCES `parbrize` (`p_id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table glasstrack_db.parbrize_auto: ~0 rows (approximately)

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
