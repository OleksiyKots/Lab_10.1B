#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h> // ��� ���������� ����������� �������� � Windows

using namespace std;

enum Speciality { COMPUTER_SCIENCE, INFORMATICS, MATH_AND_ECON, PHYSICS_AND_INFORMATICS, LABOR_EDUCATION };
string specialityStr[] = { "����'����� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };

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
    SetConsoleCP(1251); // ������������ ��������� ��� ��������
    SetConsoleOutputCP(1251);

    int N;
    cout << "������ ������� ��������: ";
    cin >> N;

    Student* students = new Student[N];
    Create(students, N);
    Print(students, N);

    double maxAvgGrade = MaxAverageGrade(students, N);
    cout << "��������� ������� ��� ����� ��������: " << maxAvgGrade << endl;

    double percentHighGrades = PercentageHighPhysicsGrades(students, N);
    cout << "³������ �������� � �������� '4' ��� '5' � ������: " << percentHighGrades << "%" << endl;

    delete[] students;
    return 0;
}

void Create(Student* students, int N) {
    int specialityInput;
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;

        cout << " �������: ";
        cin >> students[i].surname;

        cout << " ����: ";
        cin >> students[i].course;

        cout << " ������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
        cin >> specialityInput;
        students[i].speciality = static_cast<Speciality>(specialityInput);

        cout << " ������ � ������: ";
        cin >> students[i].physicsGrade;

        cout << " ������ � ����������: ";
        cin >> students[i].mathGrade;

        // ���������, ��� ����� ������ �������
        if (students[i].speciality == COMPUTER_SCIENCE) {
            cout << " ������ � �������������: ";
            cin >> students[i].programmingGrade;
        }
        else if (students[i].speciality == INFORMATICS) {
            cout << " ������ � ��������� ������: ";
            cin >> students[i].numericalMethodsGrade;
        }
        else {
            cout << " ������ � ���������: ";
            cin >> students[i].pedagogyGrade;
        }
    }
}

void Print(const Student* students, int N) {
    cout << "===================================================================================================================================" << endl;
    cout << "| � | �������          | ���� |       ������������         | Գ���� | ���������� | ������������� | ������� ������ | ��������� |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(1) << right << i + 1 << " ";
        cout << "| " << setw(18) << left << students[i].surname;
        cout << "| " << setw(4) << right << students[i].course << " ";
        cout << "| " << setw(28) << left << specialityStr[students[i].speciality];
        cout << "| " << setw(6) << right << students[i].physicsGrade << " ";
        cout << "| " << setw(10) << right << students[i].mathGrade << " ";

        // ³��������� ����� ���� � ������ ������� �� ������������
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
