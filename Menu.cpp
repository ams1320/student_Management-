//
// Created by ASUS on 6/2/2025.
//

#include "Menu.h"

StudentManager studentManage;

Menu::Menu() {
    menuOption();
}

void Menu::displayMenu() {
    std::cout << "\n======== MAIN MENU ========\n";
    std::cout << "1.Add New Student" << std::endl;
    std::cout << "2.View All Students" << std::endl;
    std::cout << "3.Search Students" << std::endl;
    std::cout << "4.Update a Student" << std::endl;
    std::cout << "5.Delete a Student" << std::endl;
    std::cout << "6.Exit.." << std::endl;
    std::cout << "Enter your Option: ";
}

void Menu::menuOption() {

    displayMenu();
    bool runApp{true};

    while (runApp) {
        int mainOption;
    char innerOption;

        std::cin >> mainOption;

        switch (mainOption) {
            case 1: {
                studentManage.addStudent();
                std::cout << "press any button to return to Main Menu: ";
                std::cin >> innerOption;
                displayMenu();
                break;
            };
            case 2: {
                studentManage.viewAllStudents();
                std::cout << "press any button to return to Main Menu: ";
                std::cin >> innerOption;
                displayMenu();
                break;
            };
            case 3: {
                studentManage.searchStudent();
                std::cout << "press any button to return to Main Menu: ";
                std::cin >> innerOption;
                displayMenu();
                break;
            };
            case 4: {
                studentManage.updateStudent();
                std::cout << "press any button to return to Main Menu: ";
                std::cin >> innerOption;
                displayMenu();
                break;
            };
            case 5: {
                studentManage.deleteStudent();
                std::cout << "press any button to return to Main Menu: ";
                std::cin >> innerOption;
                displayMenu();
                break;
            };
            case 6: {
                std::cout << "Hope you Have Great Day !!" << std::endl;
                runApp = false;
                break;
            };
            default: {
                std::cout << "Invalid Character!!!" << std::endl;
                displayMenu();
            };
        }
    }
}
