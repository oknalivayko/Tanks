#include <ctime>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

string sitename[50];
string number[50];
string email[50];
string password[50];
int k = -1;

int checksite(string check) /*Перменная возвращает 1, если массив проходит
                               проверку; возвращает 0, если не проходит*/
{
  for (int i = 0; i <= k; i++) {
    if (sitename[i] == check) {
      return 0;
    }
  }
  return 1;
}

void add()
/*Функция для добавления данных в базу. Пользователь добавляет данные о веб -
  сайта, номере телефона,
  электронном адресе и пароль. Не принимает аргументов. */
{
  string check = ""; /// check принимает данные для проверки наличия такой же
  /// строки в массиве sitename
  cout << "Enter website: ";
  cin >> check;

  if (checksite(check) == 1) {
    k++;
    sitename[k] = check;
  } else {
    cout << endl << "You have already entered data from this website" << endl;
    return;
  }
  cout << "Enter phone nubmer: ";
  cin >> number[k];
  cout << "Enter email: ";
  cin >> email[k];
  cout << "Enter password: ";
  cin >> password[k];
}

void print(int c)
/* Функция для отображения данных, введеных пользователем, в консоли. Принимает
   значение индекса c массива*/
{
  if (sitename[c] == "")
    return;
  if (k > -1) {
    cout << "Website: " << sitename[c] << endl;
    cout << "phone nubmer: " << number[c] << endl;
    cout << "Email: " << email[c] << endl;
    cout << "password: " << password[c] << endl << endl;
    system("pause");
  }
}

void printAll()
/* Функция выводит на экран список всех добавленных веб - сайтов и информацию о
   них. Не принимает аргументов. */
{
  if (k > -1) {
    for (int i = 0; i <= k; i++) {
      print(i);
    }
  }
}

void updtinfo(int c)
/*Функция обновляет данные, введенные пользователем, принимает переменную индекс
   массива.  */
{
  string check = "";
  cout << "Enter website: ";
  cin >> check;
  if (checksite(check)) {
    sitename[c] = check;
  } else {
    cout << endl << "Change the website name" << endl;
    system("pause");
    return;
  }
  cout << "Phone number: ";
  cin >> number[c];
  cout << "Email: ";
  cin >> email[c];
  cout << "password: ";
  cin >> password[c];
}
void delSite(int c)
/* Функция для удаления веб - сайта, добавленного пользователем. Принимает
   переменную индекс массива */
{
  sitename[c] = "";
  number[c] = "";
  email[c] = "";
  password[c] = "";
}

void CheckPassword()
/* Функция для проверки пароля на сложность. Пользователь вводит пароль и
 функция определяет
 уровень сложности заданного пароля на один из трех возможных классов: Weak,
 Average, Strong.*/
{
  srand(static_cast<unsigned int>(time(0)));

  string password;

  cout << endl;

  cout << "Please, enter your password again. " << endl;
  cin >> password;

  int length = password.size();
  int baseScore = 48;

  int upper = 0; /// буквы в верхнем регистре
  int symb = 0;  /// символы
  int lower = 0; /// буквы в нижнем регистре
  int digit = 0; /// цифры

  int length_bonus = 2;
  int upper_bonus = 4;
  int digit_bonus = 1;
  int lower_bonus = 3;
  int symb_bonus = 5;
  int bonus = 0;

  int i;
  for (i = 0; i < password.size(); i++) {
    if (password[i] >= 48 && password[i] <= 57) { /// 0-9
      digit++;
    }
    if (password[i] >= 97 && password[i] <= 125) { /// a-z
      lower++;
    }
    if (password[i] >= 65 && password[i] <= 90) { /// A-Z
      upper++;
    }
    if (password[i] >= 33 && password[i] <= 47) { /// symbols
      symb++;
    }
    if (password[i] == password[i + 1]) {
      length = 0;
    }
  }

  if (upper > 0 && digit > 0 && symb > 0 && lower > 0) {
    bonus = 25;
  }

  else if ((upper > 0 && digit > 0) || (upper > 0 && symb > 0) ||
           (digit > 0 && symb > 0)) {
    bonus = 15;
  }

  int score = baseScore + (length * length_bonus) + (upper * upper_bonus) +
              (digit * digit_bonus) + (symb * digit_bonus) +
              (lower * lower_bonus) + bonus;

  if (score >= 50 && score < 75) {
    cout << "Password Status: Weak" << endl;
    cout << "Your password is too simple. You can go to the Password "
            "Generator. To do this, select option 2.";
  } else if (score >= 75 && score < 125) {
    cout << "Password Status: Average" << endl;
  } else if (score > 125) {
    cout << "Password Status: Strong" << endl;
  }
}

string Generate()
/* Функция для генерации пароля. Пользователю предлагается выбрать сложность
пароля, после чего функция генерирует пароль и выводит на экран. Не принимает
аргументов.*/
{
  srand(
      static_cast<unsigned int>(time(0))); /// устанавливаем значение системных
  /// часов в качестве стартового числа
  int level;
  int length;

  do {
    cout << "1 - Weak" << endl << "2 - Average" << endl << "3 - Strong" << endl;
    cout << "Please enter password complexity. " << endl;
    cin >> level;

    if (level < 1 || level > 3)
      cout << "Invalid Complexity Entered. Please Re-Enter" << endl;
  } while (level < 1 || level > 3);

  if (level == 1)
    length = 8;
  else if (level == 2)
    length = 14;
  else
    length = 20;

  string pass(length, 'a');

  int i;

  for (i = 0; i < length; i++) {
    if (level == 1) {
      if (rand() % 3 == 0)
        pass[i] = 86 + rand() % 34;
      else
        pass[i] = 46 + rand() % 10;
    } else if (level == 2) {
      if (rand() % 4 == 0)
        pass[i] = 86 + rand() % 34;
      else if (rand() % 3 == 1)
        pass[i] = 53 + rand() % 26;
      else
        pass[i] = 46 + rand() % 10;
    } else if (level == 3) {
      if (rand() % 5 == 0)
        pass[i] = 86 + rand() % 34;
      else if (rand() % 4 == 1)
        pass[i] = 53 + rand() % 26;
      else if (rand() % 4 == 2)
        pass[i] = 32 + rand() % 15;
      else
        pass[i] = 46 + rand() % 10;
    }
  }

  cout << pass;
  cout << endl;

  return pass;
}

int find() /*Переменная для поиска строки в массиве, не принимает аргументов
                   Возвращает индекс массива совпадающей строки
                   Возвращает -1, если база пустая*/
{
  if (k < 0)
    return -1;

  string check;
  cout << "Enter website: ";
  cin >> check;

  for (int i = 0; i <= k; i++) {
    if (sitename[i] == check) {
      return i;
    }
  }

  return 1;
}

int main() {
  char op;
  do {

    system("cls");
    cout << "1. Add website" << endl;
    cout << "2. Generate Password" << endl;
    cout << "3. List of all websites" << endl;
    cout << "4. Search" << endl;
    cout << "5. Update" << endl;
    cout << "6. Delete" << endl;
    cout << "7. Save" << endl;
    cout << "8. Open" << endl;
    cout << "9. Exit" << endl << endl;
    cout << "Choose the option:";
    cin >> op;

    switch (op) {

    case '1': {
      add();
      cout << "Website added" << endl;
      cout << "Do you want to check your password for strength (y/n): ";
      getchar();
      char opt = getchar();
      if (opt == 'y' || opt == 'Y') {
        CheckPassword();
      }
      cout << endl << endl;
      system("pause");
      break;
    }

    case '2': {
      cout << "You can generate password and choose the difficulty level for "
              "your password."
           << endl;
      string pass = Generate();
      cout << "Do you want to change your password to the generated one? "
              "(y/n): ";
      getchar();
      char opt = getchar();
      if (opt == 'y' || opt == 'Y') {
        int c = find();
        if (c > -1) {
          password[c] = pass;
        }
      }
      system("pause");
      break;
    }

    case '3': {
      printAll();
      system("pause");
      break;
    }

    case '4': {
      int c = find();
      if (c > -1) {
        print(c);
      }
      break;
    }

    case '5': {
      int c = find();
      if (c > -1) {
        updtinfo(c);
      }
      break;
    }

    case '6': {
      int c = find();
      if (c > -1) {
        delSite(c);
      }
      break;
    }

    case '7': {
      ofstream out;
      ofstream fout;
      out.open("sitename.txt");
      fout.open("list.txt");
      if (!out.is_open()) {
        cerr << "error\n";
      }
      fout << "WEBSITE\t\t\t"
           << "\t\t\t"
           << "PHONE NUMBER\t\t\t"
           << "\t\t\t"
           << "EMAIL\t\t\t"
           << "\t\t\t"
           << "PASSWORD\t\t\t" << endl;
      for (int i = 0; i <= k; i++) {
        out << sitename[i] << endl;
        out << number[i] << endl;
        out << email[i] << endl;
        out << password[i] << endl;
        fout << sitename[i] << "\t\t\t";
        fout << "\t\t\t" << number[i] << "\t\t\t";
        fout << "\t\t\t" << email[i] << "\t\t\t";
        fout << "\t\t\t" << password[i] << "\t\t\t" << endl;
      }
      fout.close();
      out.close();
      break;
    }

    case '8': {
      ifstream in;
      in.open("sitename.txt");
      for (int i = 0; i < 50; i++) {
        getline(in, sitename[i]);
        getline(in, number[i]);
        getline(in, email[i]);
        getline(in, password[i]);
      }
      int j = 0;
      while (sitename[j] != "") {
        j++;
      }
      k = j - 1;
      in.close();
      system("pause");
      break;
    }

    case '9': {
      continue;
      break;
    }
    }

  } while (op != '9');

  return 0;
}
