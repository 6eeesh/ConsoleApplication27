#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

class Student {
private:
    string last_name;
    string first_name;
    string middle_name;
    Date birth_date;
    string home_address;
    string phone_number;
    int grades[5];

public:
    Student(string first, string last) : first_name(first), last_name(last) {

    }

    void SetBirthDate(const Date& date) {
        birth_date = date;
    }

    Date GetBirthDate() const {
        return birth_date;
    }

    void SetHomeAddress(const string& address) {
        home_address = address;
    }

    string GetHomeAddress() const {
        return home_address;
    }

    void SetPhoneNumber(const string& phone) {
        phone_number = phone;
    }

    string GetPhoneNumber() const {
        return phone_number;
    }

    void SetLastName(const string& last) {
        last_name = last;
    }

    string GetLastName() const {
        return last_name;
    }

    void AddGrade(int subject_index, int grade) {
        if (subject_index >= 0 && subject_index < 5) {
            grades[subject_index] = grade;
        }
    }

    int GetGrade(int subject_index) const {
        if (subject_index >= 0 && subject_index < 5) {
            return grades[subject_index];
        }
        return -1;
    }

    void ShowStudentInfo() const {
        cout << "Фамилия: " << last_name << endl;
        cout << "Имя: " << first_name << endl;
        cout << "Отчество: " << middle_name << endl;
        cout << "Дата рождения: " << birth_date << endl;
        cout << "Домашний адрес: " << home_address << endl;
        cout << "Телефонный номер: " << phone_number << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Оценка по предмету " << (i + 1) << ": " << grades[i] << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "");
    Student student("Антон", "Иванов");

    student.SetBirthDate(Date(2000, 1, 1));
    student.SetHomeAddress("ул. Добровольского, 123");
    student.SetPhoneNumber("+38(097)264-18-54");

    student.AddGrade(0, 95);
    student.AddGrade(1, 88);


    student.ShowStudentInfo();

    student.SetLastName("Петров");
    student.SetPhoneNumber("+38(097)234-13-24");

    cout << "Измененная фамилия: " << student.GetLastName() << endl;
    cout << "Измененный телефонный номер: " << student.GetPhoneNumber() << endl;

    return 0;
}
