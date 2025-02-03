#pragma once
#ifndef LOGCSV_H
#define LOGCSV_H

#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

class LogCSV {
public:
    static std::string getCurrentTimestamp();
    static void writeLog(const std::string& message);
    static void writeCSV(const std::string& filename);
    static void appendCSV(const std::string& filename, int id, const std::string& name, int score);
};

#endif // LOGCSV_H
