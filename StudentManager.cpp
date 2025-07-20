#include "StudentManager.h"
#include "sqlite3.h"


StudentManager::StudentManager() {}

void StudentManager::addStudent() {
    int age,id;
    std::string name,course;
    students = loadFromFile();

    std::cout << "Enter Student id: ";
    std::cin >> id ;
    std::cout << "Enter Student name: ";
    std::cin >> name;
    std::cout << "Enter Student age: ";
    std::cin >> age;
    std::cout << "Enter Student course: ";
    std::cin >> course;
    Student newStudent {id,name,age,course};
    students.push_back(newStudent);

    saveToFile(students);
    std::cout << "Student Created Successfully!"<<std::endl;
}

void StudentManager::viewAllStudents() {

   students = loadFromFile();
    if(!students.empty()){
        for(int i{0}; i<students.size(); i++){
            std::cout << students[i]<<"\n";
        }
    }
    else{
        std::cout << "there is no student..."<<std::endl ;
    }
}

void StudentManager::searchStudent() {

    students = loadFromFile();
    int searchId;

    std::cout << "Enter student ID to search: ";
    std::cin >> searchId;

    bool found = false;
    for( auto& student : students) {
        if (student.getId() == searchId) {
            std::cout << student << std::endl;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Student with ID " << searchId << " not found.\n";
    }
}

void StudentManager::updateStudent() {

    students = loadFromFile();
    int targetId;

    std::cout << "Enter ID of the student to update: ";
    std::cin >> targetId;

    bool found = false;
    for (auto& student : students) {
        if (student.getId() == targetId) {
            found = true;
            std::string name, course;
            int age;

            std::cout << "Enter new name (current name is "<<(student.getName())<<"): ";
            std::cin >> name;
            std::cout << "Enter new age (current age is "<<(student.getAge())<<"):";
            std::cin >> age;
            std::cout << "Enter new course(current course is "<<(student.getCourse())<<"): ";
            std::cin >> course;

            student.setStudent(targetId, name, age, course);
            break;
        }
    }

    if (found) {
        saveToFile(students);
        std::cout << "Student updated successfully.\n";
    } else {
        std::cout << "Student with ID " << targetId << " not found.\n";
    }
}

void StudentManager::deleteStudent() {
    students = loadFromFile();

    int targetId;
    std::cout << "Enter ID of the student to delete: ";
    std::cin >> targetId;

    bool found = false;
    auto file = students.begin();
    while (file != students.end()) {
        if (file->getId() == targetId) {
            file = students.erase(file);
            found = true;
            break;
        } else {
            ++file;
        }
    }

    if (found) {
        saveToFile(students);
        std::cout << "Student deleted successfully.\n";
    } else {
        std::cout << "Student with ID " << targetId << " not found.\n";
    }
}

void StudentManager::saveToFile(const std::vector<Student> students) {
    std::ofstream studentFile("students.txt");
    if (!studentFile) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    for (size_t i = 0; i < students.size(); ++i) {
        studentFile << students[i] << std::endl;
    }
    studentFile.close();
}

std::string StudentManager::trim(std::string str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    return (first == std::string::npos) ? "" : str.substr(first, (last - first + 1));
}

std::vector<std::string> StudentManager::split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

std::vector<Student> StudentManager::loadFromFile() {
    std::vector<Student> students;
    std::ifstream file("students.txt");
    std::string line;

    while (std::getline(file, line)) {
        // Split entire line by ','
        auto parts = split(line, ',');

        if (parts.size() < 4) continue; // invalid format

        int id = std::stoi(parts[0].substr(parts[0].find(":") + 1));
        std::string name = parts[1].substr(parts[1].find(":") + 1);
        int age = std::stoi(parts[2].substr(parts[2].find(":") + 1));
        std::string course = parts[3].substr(parts[3].find(":") + 1);

        // Trim whitespace if needed (optional)
        name = trim(name);
        course = trim(course);

        students.emplace_back(id, name, age, course);
    }

    return students;
}




