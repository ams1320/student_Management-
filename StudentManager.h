
#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "iostream"
#include "fstream"
#include "sstream"
#include "vector"
#include "string"
#include "Student.h"


class StudentManager {
private:
    std::vector<Student> students;
public:

    StudentManager();

    void addStudent();

    void viewAllStudents();

    void searchStudent();

    void updateStudent();

    void deleteStudent();

    void saveToFile(std::vector<Student> students);

    std::string trim(std::string str);

    std::vector<std::string> split(const std::string& s, char delimiter);

    std::vector<Student> loadFromFile();

};

#endif