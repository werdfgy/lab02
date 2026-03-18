#include <iostream>
#include <string>

int main() {
    // Переменная для хранения имени пользователя
    std::string name;

    // Запрос имени у пользователя
    std::cout << "Enter your name: ";
    std::cin >> name;

    // Вывод приветствия с именем
    std::cout << "Hello world from " << name << std::endl;

    return 0;
}
