#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h> // Для коректного відображення кирилиці у Windows

using namespace std;

enum Speciality { COMPUTER_SCIENCE, INFORMATICS, MATH_AND_ECON, PHYSICS_AND_INFORMATICS, LABOR_EDUCATION };
string specialityStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student {
    string surname;
    int course;
    Speciality speciality;
    int physicsGrade;
    int mathGrade;
    union {
        int programmingGrade;
        int numericalMethodsGrade;
        int pedagogyGrade;
    };
};

void Create(Student* students, int N);
void Print(const Student* students, int N);
double MaxAverageGrade(const Student* students, int N);
double PercentageHighPhysicsGrades(const Student* students, int N);

int main() {
    SetConsoleCP(1251); // Установлення кодування для кирилиці
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* students = new Student[N];
    Create(students, N);
    Print(students, N);

    double maxAvgGrade = MaxAverageGrade(students, N);
    cout << "Найбільший середній бал серед студентів: " << maxAvgGrade << endl;

    double percentHighGrades = PercentageHighPhysicsGrades(students, N);
    cout << "Відсоток студентів з оцінками '4' або '5' з фізики: " << percentHighGrades << "%" << endl;

    delete[] students;
    return 0;
}

void Create(Student* students, int N) {
    int specialityInput;
    for (int i = 0; i < N; i++) {
        cout << "Студент № " << i + 1 << ":" << endl;

        cout << " Прізвище: ";
        cin >> students[i].surname;

        cout << " Курс: ";
        cin >> students[i].course;

        cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
        cin >> specialityInput;
        students[i].speciality = static_cast<Speciality>(specialityInput);

        cout << " Оцінка з фізики: ";
        cin >> students[i].physicsGrade;

        cout << " Оцінка з математики: ";
        cin >> students[i].mathGrade;

        // Визначаємо, яка третя оцінка потрібна
        if (students[i].speciality == COMPUTER_SCIENCE) {
            cout << " Оцінка з програмування: ";
            cin >> students[i].programmingGrade;
        }
        else if (students[i].speciality == INFORMATICS) {
            cout << " Оцінка з чисельних методів: ";
            cin >> students[i].numericalMethodsGrade;
        }
        else {
            cout << " Оцінка з педагогіки: ";
            cin >> students[i].pedagogyGrade;
        }
    }
}

void Print(const Student* students, int N) {
    cout << "===================================================================================================================================" << endl;
    cout << "| № | Прізвище          | Курс |       Спеціальність         | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(1) << right << i + 1 << " ";
        cout << "| " << setw(18) << left << students[i].surname;
        cout << "| " << setw(4) << right << students[i].course << " ";
        cout << "| " << setw(28) << left << specialityStr[students[i].speciality];
        cout << "| " << setw(6) << right << students[i].physicsGrade << " ";
        cout << "| " << setw(10) << right << students[i].mathGrade << " ";

        // Відображаємо тільки одну з оцінок залежно від спеціальності
        if (students[i].speciality == COMPUTER_SCIENCE) {
            cout << "| " << setw(13) << right << students[i].programmingGrade << " ";
            cout << "| " << setw(17) << right << " ";
            cout << "| " << setw(11) << right << " ";
        }
        else if (students[i].speciality == INFORMATICS) {
            cout << "| " << setw(14) << right << " ";
            cout << "| " << setw(15) << right << students[i].numericalMethodsGrade << " ";
            cout << "| " << setw(11) << right << " ";
        }
        else {
            cout << "| " << setw(14) << right << " ";
            cout << "| " << setw(16) << right << " ";
            cout << "| " << setw(10) << right << students[i].pedagogyGrade << " ";
        }
        cout << "|" << endl;
    }

    cout << "===================================================================================================================================" << endl;
}

double MaxAverageGrade(const Student* students, int N) {
    double maxAvg = 0.0;
    for (int i = 0; i < N; i++) {
        int total = students[i].physicsGrade + students[i].mathGrade;
        if (students[i].speciality == COMPUTER_SCIENCE) {
            total += students[i].programmingGrade;
        }
        else if (students[i].speciality == INFORMATICS) {
            total += students[i].numericalMethodsGrade;
        }
        else {
            total += students[i].pedagogyGrade;
        }
        double avg = static_cast<double>(total) / 3;
        if (avg > maxAvg) {
            maxAvg = avg;
        }
    }
    return maxAvg;
}

double PercentageHighPhysicsGrades(const Student* students, int N) {
    int countHighGrades = 0;
    for (int i = 0; i < N; i++) {
        if (students[i].physicsGrade >= 4) {
            countHighGrades++;
        }
    }
    return (static_cast<double>(countHighGrades) / N) * 100;
}
