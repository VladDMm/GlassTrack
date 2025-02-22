﻿#pragma once
#ifndef ERROR_DEFINE_H
#define ERROR_DEFINE_H


// 20 - 30 SQL ERRORS
#define WARN_SQL_ERROR           20  // Eroare în execuția SQL
#define WARN_SQL_SEARCH          21  // Eroare in cautarea SQL
#define WARN_SQL_UPDATE          22  // Eroare la actualizare SQL
#define WARN_SQL_SORT            23  // Eroare la sortare
// 30 - 40 LOAD DATA ERRORS
#define WARN_DATA_LOAD_FAIL      30  // Eroare la încărcarea datelor
// 40 - 50 OTHER ERRORS
#define WARN_NO_SELECTED_ROW     40  // Nu există rând selectat pentru ștergere
#define WARN_NO_SELECTED_PRODUCT 41  // Nu exista produs selectat
// 50 - 60 ERRORS IN DELETE DATA
#define WARN_DELETE_FAILED       50  // Eroare la ștergerea datelor
// 60 - 70 SERVER ERRORS
#define WARN_SLOW_RESPONSE       60  // Serverul răspunde lent
#define WARN_NO_RESPONSE_SERVER  61  // Serverul nu raspunde
// RESOURCES ERRORS
#define WARN_LOW_RESOURCES       70  // Resurse insuficiente

#endif // ERROR_DEFINE_H