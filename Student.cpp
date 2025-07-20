#include "Student.h"

Student::Student(int id, std::string name, int age, std::string course) {
    setStudent( id,name, age, course);
}

int Student::getId() {
    return id;
}

std::string Student::getName() {
    return name;
}

int Student::getAge() {
    return age;
}

std::string Student::getCourse() {
    return course;
}

void Student::setStudent(int id, std::string name, int age, std::string course) {
    this->id = id;
    this->name = name;
    this->age = age;
    this->course = course;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "ID: " << student.id
       << ", Name: " << student.name
       << ", Age: " << student.age
       << ", Course: " << student.course ;
    return os;
}