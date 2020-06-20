МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
### Отчёт по лабораторной работе № 5<br/> по дисциплине "Программирование"
<br/>
​
студента 1 курса группы ПИ-б-о-192(2)  
<br/>Кодаченко Никиты Владимировича 
<br/>направления подготовки 09.03.04 "Программная инженерия" 

<br/><br/>
<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>
​
Симферополь, 2019

#### Цель

* Закрепить навыки работы с перечислениями;
* Закрепить навыки работы с структурами;
* Освоить методы составления многофайловых программ.

#### Ход работы

1. Код программы
```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
    int Survivor = 0;
    int Survivor_1 = 0;
    int Survivor_2 = 0;
    int Survivor_3 = 0;
    int Survivor_man = 0;
    int Survivor_woman = 0;
    int number_age = 0;
    int number_age_man = 0;
    int number_age_woman = 0;
    int average_age = 0;
    int average_age_man = 0;
    int average_age_woman = 0;
    int State_S = 0;
    int State_C = 0;
    int State_Q = 0;
    string ID_minor;
    ID_minor.clear();
    ifstream csv("train.csv");
    if (!csv.is_open()) {
        cout << "ERROR! File not found!"<<endl;
    }
    else {
        string s_csv;
        getline(csv, s_csv, '\r');
        while (!csv.eof()) {
            bool End_string = false;
            int Table_column = 1;
            getline(csv, s_csv, '\r');
            string ID;
            ID.clear();
            bool is_survivor = false;
            int Pclass = 0;
            int Sex = -1;//0=woman, 1=man, -1-не выбран;
            string Age;
            Age.clear();
            string Embarked;
            Embarked.clear();
            bool string_column = false;
            for (int k = 0; !End_string; k++) {
                if (s_csv[k] == '\0') {
                    End_string = true;
                }
                else if (s_csv[k] == ',' && !string_column) {
                    Table_column++;
                    continue;
                }
                else {
                    switch (Table_column) {
                    case 1:
                        ID += s_csv[k];
                        break;
                    case 2:
                        if (s_csv[k] == '1') {
                            is_survived = true;
                        }
                        break;
                    case 3:
                        switch (s_csv[k])
                        {
                        case '1':
                            Pclass = 1;
                            break;
                        case '2':
                            Pclass = 2;
                            break;
                        case '3':
                            Pclass = 3;
                            break;
                        }
                        break;
                    case 4:
                        if (s_csv[k] == '\"' && string_column) {
                            string_column = false;
                        }
                        else if (s_csv[k] == '\"' && !string_column) {
                            string_column = true;
                        }
                        break;
                    case 5:
                        if (Sex == -1) {
                            if (s_csv[k] == 'm') {
                                Sex = 1;
                            }
                            else {
                                Sex = 0;
                            }
                        }
                        break;
                    case 6:
                        Age += s_csv[k];
                        break;
                    case 12:
                        Embarked += s_csv[k];
                    default:
                        break;
                    }
                }
            }
            if (is_survivor) {
                Survivor++;
                switch (Pclass)
                {
                case 1:
                    Survivor_1++;
                    break;
                case 2:
                    Survivor_2++;
                    break;
                case 3:
                    Survivor_3++;
                    break;
                default:
                    break;
                }
                if (Sex == 1) {
                    Survivor_man++;
                }
                else if (Sex == 0) {
                    Survivor_woman++;
                }
            }
            if (!Age.empty()) {
                int num_age = stoi(Age);
                average_age += num_age;
                number_age++;
                if (Sex == 1) {
                    average_age_man += num_age;
                    number_age_man++;
                }
                else if (Sex == 0) {
                    average_age_woman += num_age;
                    number_age_woman++;
                }
                if (num_age < 18) {
                    ID_minor += ID + ',';
                }
            }
            switch (Embarked[0])
            {
            case 'S':
                State_S++;
                break;
            case 'C':
                State_C++;
                break;
            case 'Q':
                State_Q++;
                break;

            default:
                break;
            }
        }
        csv.close();
        ofstream Table("table.csv");
        if (!Table.is_open()) {
            cout << "ERROR! File don`t create!" << endl;
        }
        else {
            Table << "\"Хар-ка\",\"Результат\"\r";
            Table << "\"Общее число выживших\"," << Survivor <<"\r";
            Table << "\"Общее число выживших из 1 класса\"," << Survivor_1 << "\r";
            Table << "\"Общее число выживших из 2 класса\"," << Survivor_2 << "\r";
            Table << "\"Общее число выживших из 3 класса\"," << Survivor_3 << "\r";
            Table << "\"Общее число выживших мужчин\"," << Survivor_man << "\r";
            Table << "\"Общее число выживших женщин\"," << Survivor_woman << "\r";
            if (number_age != 0) {
                Table << "\"Средний возраст\"," << fixed << setprecision(2) << (float)average_age / number_age << "\r";
            }
            else {
                Table << "\"Средний возраст\"," << fixed << setprecision(2) <<0<< "\r";
            }
            if (number_age_man != 0) {
                Table << "\"Средний возраст мужчин\"," << fixed << setprecision(2) << (float)average_age_man / number_age_man << "\r";
            }
            else {
                Table << "\"Средний возраст мужчин\"," << fixed << setprecision(2) <<0<< "\r";
            }
            if (number_age_woman != 0) {
                Table << "\"Средний возраст женщин\"," << fixed << setprecision(2) << (float)average_age_woman / number_age_woman << "\r";
            }
            else {
                Table << "\"Средний возраст женщин\"," << fixed << setprecision(2) << 0 << "\r";
            }
            if (State_C >= State_Q && State_C >= State_S) {
                Table << "\"Штат, в котором больше всего пасажиров\"," << "\"Cherbourg\"" << "\r";
            }
            else if (State_S >= State_Q && State_S >= State_C) {
                Table << "\"Штат, в котором больше всего пасажиров\"," << "\"Southampton\"" << "\r";
            }
            else if (State_Q >= State_C && State_Q >= State_S) {
                Table << "\"Штат, в котором больше всего пасажиров\"," << "\"Queenstown\"" << "\r";
            }
            ID_minor.erase(ID_minor.size() - 1);
            Table << "\"ID несовершеннолетних\",\"" << ID_minor << "\"\r";
            Table.close();
        }
    }
}
```
2. Таблица с характеристиками

    | Характеристика | Результат |
    |---|---|
    |  Общее число выживших | 342 |
    |  Общее число выживших из 1 класса | 136 |
    |  Общее число выживших из 2 класса | 87 |
    |  Общее число выживших из 3 класса | 119 |
    |  Общее число выживших мужчин | 109 |
    |  Общее число выживших женщин | 233 |
    |  Средний возраст | 29.68 |
    |  Средний возраст мужчин | 30.70 |
    |  Средний возраст женщин | 27.90 |
    |  Штат, в котором больше всего пасажиров | Southampton |
    |  ID несовершеннолетних | 8,10,11,15,17,23,25,40,44,51,59,60,64,69,72,79,85,87,112,115,120,126,139,148,157,164,165,166,172,173,183,184,185,194,206,209,221,234,238,262,267,279,283,298,306,308,330,334,341,349,353,375,382,387,390,408,420,434,436,446,447,449,470,480,481,490,501,505,531,533,536,542,543,550,551,575,619,635,643,645,684,687,690,692,721,722,732,747,751,752,756,765,778,781,782,788,789,792,803,804,814,820,825,828,831,832,842,845,851,853,854,870,876|
3. Ссылка на [Файл](https://github.com/NikitaGitHub19/GitHubCFU/blob/master/Lab5/table.csv "Таблица с характеристиками в формате csv")
   
#### Ввывод
В ходе лабораторной работы были получены такие навыки, как
* работа с CSV файлами;
* чтение/запись файлов.

