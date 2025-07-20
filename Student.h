//
// Created by ASUS on 6/2/2025.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

class Student {
private:
    int id, age;
    std::string name,course;
public:

    Student(int id, std::string name, int age, std::string course);

    void setStudent(int id, std::string name, int age, std::string course);

    int getId();

    std::string getName();

    int getAge();

    std::string getCourse();

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
};


#endif
