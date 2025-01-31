-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               11.4.4-MariaDB - mariadb.org binary distribution
-- Server OS:                    Win64
-- HeidiSQL Version:             12.8.0.6908
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

-- Dumping structure for table glasstrack_db.automobile
CREATE TABLE IF NOT EXISTS `automobile` (
  `a_id` int(11) NOT NULL AUTO_INCREMENT,
  `a_marca` varchar(300) NOT NULL,
  `a_model` varchar(300) DEFAULT NULL,
  PRIMARY KEY (`a_id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table glasstrack_db.automobile: ~8 rows (approximately)
INSERT INTO `automobile` (`a_id`, `a_marca`, `a_model`) VALUES
	(1, 'VW', 'Caddy'),
	(2, 'Audi', 'A6'),
	(3, 'VW', 'Polo'),
	(4, 'VW', 'Passat'),
	(5, 'Mercedes', 'GLK'),
	(6, 'Mercedes', 'GLB'),
	(7, 'Renault', 'Megane'),
	(8, 'Audi', 'Q8');

-- Dumping structure for table glasstrack_db.celula
CREATE TABLE IF NOT EXISTS `celula` (
  `id_celula` int(11) NOT NULL AUTO_INCREMENT,
  `nume_celula` char(50) DEFAULT NULL,
  PRIMARY KEY (`id_celula`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table glasstrack_db.celula: ~2 rows (approximately)
INSERT INTO `celula` (`id_celula`, `nume_celula`) VALUES
	(1, 'C1'),
	(2, 'c2');

-- Dumping structure for table glasstrack_db.parbrize
CREATE TABLE IF NOT EXISTS `parbrize` (
  `p_id` int(11) NOT NULL AUTO_INCREMENT,
  `p_code` char(255) NOT NULL,
  `p_origine` char(155) DEFAULT NULL,
  `p_count` int(11) NOT NULL,
  `p_price` decimal(20,6) NOT NULL,
  PRIMARY KEY (`p_id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table glasstrack_db.parbrize: ~6 rows (approximately)
INSERT INTO `parbrize` (`p_id`, `p_code`, `p_origine`, `p_count`, `p_price`) VALUES
	(1, '1234af-b', 'China', 0, 1300.000000),
	(2, '45637AFG', 'Germania', 7, 2700.000000),
	(3, '52342fadas', 'Olanda', 3, 2000.000000),
	(4, '9856FGV', 'Franta', 4, 1800.000000),
	(5, '8986GRQ', 'Germania', 4, 3100.000000),
	(6, '1F45HB', 'Franta', 3, 1500.000000);

-- Dumping structure for table glasstrack_db.parbrize_auto
CREATE TABLE IF NOT EXISTS `parbrize_auto` (
  `pa_id` int(11) NOT NULL AUTO_INCREMENT,
  `a_id` int(11) NOT NULL,
  `p_id` int(11) NOT NULL,
  `sectia_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`pa_id`) USING BTREE,
  KEY `auto_fk1` (`a_id`),
  KEY `parbrize_fk2` (`p_id`),
  KEY `sectia_fk` (`sectia_id`),
  CONSTRAINT `auto_fk1` FOREIGN KEY (`a_id`) REFERENCES `automobile` (`a_id`) ON DELETE CASCADE,
  CONSTRAINT `parbrize_fk2` FOREIGN KEY (`p_id`) REFERENCES `parbrize` (`p_id`) ON DELETE CASCADE,
  CONSTRAINT `sectia_fk` FOREIGN KEY (`sectia_id`) REFERENCES `sectia` (`id_sectia`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table glasstrack_db.parbrize_auto: ~3 rows (approximately)
INSERT INTO `parbrize_auto` (`pa_id`, `a_id`, `p_id`, `sectia_id`) VALUES
	(1, 4, 1, 1),
	(6, 8, 5, 1),
	(7, 7, 6, 3);

-- Dumping structure for table glasstrack_db.sectia
CREATE TABLE IF NOT EXISTS `sectia` (
  `id_sectia` int(11) NOT NULL AUTO_INCREMENT,
  `nume_sectie` char(100) NOT NULL,
  `id_celula` int(11) DEFAULT NULL,
  PRIMARY KEY (`id_sectia`),
  KEY `celula_fk` (`id_celula`),
  CONSTRAINT `celula_fk` FOREIGN KEY (`id_celula`) REFERENCES `celula` (`id_celula`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table glasstrack_db.sectia: ~3 rows (approximately)
INSERT INTO `sectia` (`id_sectia`, `nume_sectie`, `id_celula`) VALUES
	(1, 'S1', 1),
	(2, 'S2', 1),
	(3, 'S3', 2);

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
