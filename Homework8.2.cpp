#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

void divide(int d)
{
    if (d == 0)
        cout << "Делить на ноль нельзя!";
    else
        cout << "Частное: " << 1024 / d << endl;
}

class FileWasNotOpenedException : public exception {
public:
    const char* what() const throw() {
        return "Файл не был открыт.";
    }
};

string readFile(string filename) {
    ifstream file;
    file.open(filename);

    if (!file.is_open()) {
        throw FileWasNotOpenedException();
    }

    string content;
    string line;

    while (getline(file, line)) {
        content += line + "\n";
    }

    file.close();

    return content;
}


int main()
{
    setlocale(0, "Rus");

    int d;
    cout << "Введите делитель: " << endl;
    cin >> d;
    divide(d);
    cin.ignore();

    // Задание 2

    cout << "Открываем файл..." << endl;
    try {
        string content = readFile("example.txt");
        cout << content;
    }
    catch (FileWasNotOpenedException& e) {
        cout << e.what() << endl;
    }

   // Задание 3

    string i;
    cout << "Введите математическую операцию: " << endl;
    getline(cin, i);

    char op;
    double a, b;

    if (sscanf(i.c_str(), "%lf %c %lf", &a, &op, &b) != 3) {
        cout << "Неправильный формат ввода." << endl;
        return;
    }

    double result;
    switch (op) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (b == 0)
        {
            cout << "Делить на ноль нельзя!" << endl;
            return;
        }
        else
            result = a / b;
        break;
    default:
        cout << "Неверный оператор." << endl;
        return;
    }

    cout << "Результат: " << result << endl;

    return;

}