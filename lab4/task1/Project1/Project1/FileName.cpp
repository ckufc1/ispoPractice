#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;


// функция для установки цвета по названию
void setConsoleColor(const string& color) {
    if (color == "red") {
        system("color 4F"); // красный фон + белый текст
    }
    else if (color == "blue") {
        system("color 1F"); // синий фон + белый текст
    }
    else if (color == "green") {
        system("color 2F"); // зелёный фон + белый текст
    }
    else if (color == "yellow") {
        system("color 6F"); // жёлтый фон + белый текст
    }
    else if (color == "white") {
        system("color 7F"); // белый фон + чёрный текст 
    }
    else {
        system("color 0F"); // по умолчанию: чёрный фон + белый текст
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string pet, color;

    ifstream fin("settings.txt"); //Создает объект fin для чтения из файла и открывает файл

    if (fin.is_open()) {// Проверка открытия файла
        // читаем сохраненные данные
        fin >> pet >> color;// Читает данные из файла (аналогично cin)
        fin.close(); //Закрывает файл и освобождает ресурсы

        setConsoleColor(color);

        cout << "Любимое животное: " << pet << endl;

        char choice;
        cout << "\nХотите изменить поменять выбор? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Введите новое любимое животное (dog, cat, parrot): ";
            cin >> pet;


            ofstream fout("settings.txt"); //Создает объект fout для записи в файл и открывает файл
            //ofstream fout("settings.txt", ios::app); // Открываем для добавления, если нужно внести еще какие-то параметры в файл ios::app, если не указывать по умолчанию очищает
            fout << pet << " " << color; //Записывает данные в файл (аналогично cout)
            fout.close();

            cout << "Выбор изменен" << endl;
        }

        cout << "\nХотите изменить поменять цвет консоли? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Введите новый любимый цвет (red, blue, green, yellow, white): ";
            cin >> color;


            ofstream fout("settings.txt"); //Создает объект fout для записи в файл и открывает файл
            //ofstream fout("settings.txt", ios::app); // Открываем для добавления, если нужно внести еще какие-то параметры в файл ios::app, если не указывать по умолчанию очищает
            fout << pet << " " << color; //Записывает данные в файл (аналогично cout)
            fout.close();

            cout << "Выбор изменен" << endl;
        }
    }
    else {
        // файла нет – вводим новые настройки
        cout << "Введите ваше любимое животное (dog, cat, parrot): ";
        cin >> pet;
        cout << "Введите ваш любимый цвет (red, blue, green, yellow, white): ";
        cin >> color;

        ofstream fout("settings.txt");
        fout << pet << " " << color;
        fout.close();

        cout << "Настройки сохранены!" << endl;
    }

    return 0;
}
