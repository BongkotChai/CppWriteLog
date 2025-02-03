
#include "LogCSV.h"
#include <codecvt>
#include <locale>

// ฟังก์ชันดึงวันที่และเวลาปัจจุบัน
std::string LogCSV::getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm local_tm;
    localtime_s(&local_tm, &now_c); // ใช้ localtime_s() สำหรับ Visual Studio

    std::ostringstream oss;
    oss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// ฟังก์ชันเขียน Log File
void LogCSV::writeLog(const std::string& message) {
    std::ofstream logFile("logfile.log", std::ios::app);
    if (logFile.is_open()) {
        logFile.imbue(std::locale(logFile.getloc(), new std::codecvt_utf8<wchar_t>)); // ตั้งค่า UTF-8
        logFile << "[" << getCurrentTimestamp() << "] " << message << std::endl;
        logFile.close();
    }
    else {
        std::cerr << "ไม่สามารถเปิดไฟล์ Log ได้" << std::endl;
    }
}

// ฟังก์ชันเขียนไฟล์ CSV ใหม่
void LogCSV::writeCSV(const std::string& filename) {
    std::ofstream csvFile(filename);
    if (csvFile.is_open()) {
        csvFile << "ID,Name,Score,Timestamp\n";
        csvFile << "1,John,85," << getCurrentTimestamp() << "\n";
        csvFile << "2,Alice,92," << getCurrentTimestamp() << "\n";
        csvFile << "3,Bob,78," << getCurrentTimestamp() << "\n";
        csvFile.close();
        std::cout << "บันทึกข้อมูลลงไฟล์ " << filename << " เรียบร้อย" << std::endl;
    }
    else {
        std::cerr << "ไม่สามารถเปิดไฟล์ CSV ได้" << std::endl;
    }
}

// ฟังก์ชันเพิ่มข้อมูล CSV แบบ Append
void LogCSV::appendCSV(const std::string& filename, int id, const std::string& name, int score) {
    std::ofstream csvFile(filename, std::ios::app);
    if (csvFile.is_open()) {
        csvFile << id << "," << name << "," << score << "," << getCurrentTimestamp() << "\n";
        csvFile.close();
        std::cout << "เพิ่มข้อมูลลงไฟล์ " << filename << " เรียบร้อย" << std::endl;
    }
    else {
        std::cerr << "ไม่สามารถเปิดไฟล์ CSV ได้" << std::endl;
    }
}


