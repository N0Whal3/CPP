МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"Крымский Федеральный Университет им. В. И. Вернадского"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>

### Отчёт по лабораторной работе № 1<br/> по дисциплине "Программирование"
<br/>

студента 1 курса группы ПИ-б-о-192(2)  
Кодаченко Никиты Владимирович
направления подготовки 09.03.04 "Программная инженерия"  
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>

Симферополь, 2019

#### Цель: изучить основные возможности создания и отладки программ в IDE Qt Creator. <br/>
#### Ход работы <br/>

**1. Как создать консольное приложение С++ в IDE Qt Creator без использования компонентов Qt?** <br/>
Для того чтобы создать данное приложение, требуеться перейти во вкладку `"Файл"-"Создать файл или проект"`. Далее выбрать проект без QT, после чего приложение на С++. Далее выбираем директорию. <br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_1.1.png?raw=true)<br/>Рис.1 Вкладка `Файл`<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_1.2.png?raw=true)<br/>Рис.2 Окно `Новый файл или проект`<br/>
**2. Как изменить цветовую схему (оформление) среды?** <br/>
Выбираем вкладку `"Инструменты"-"Параметры"-"Среда"`. Там где написанно тема выбираем нужную и перезагружаем программу.<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_2.1.png?raw=true)<br/>Рис.3 Вкладка `Инструменты` подвкалдка`Параметры`<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_2.2.png?raw=true)<br/>Рис.4 Параметры QtCreator<br/>
**3.Как закомментировать/раскомментировать блок кода средствами Qt Creator?** <br/>
Выделяем нужную часть кода и нажимаем Ctrl+/<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_3.1.png?raw=true)<br/>Рис.5 Код программы без комментария<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_3.2.png?raw=true)<br/>Рис.6 Код программы с закоментированной строкой<br/>
**4.Как открыть в проводнике Windows папку с проектом средствами Qt Creator?** <br/>
Для этого требуеться нажать на вкладку `"Файл"-"Открыть файл или проект"`, а затем перейти в директорию программы и запустить файл `.pro` <br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_4.1.png?raw=true)<br/>Рис.7 Вкладка `Файл` подвкладка `Открыть файл ил проект`<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_4.2.png?raw=true)<br/>Рис.8 Открытие файла<br/>
**5.Какое расширение файла-проекта используется Qt Creator?**<br/>
`.pro`<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_5.1.png?raw=true)<br/>Рис.9 Расширение файла<br/>
**6.Как запустить код без отладки?**<br/>
Нажать на зелёный треугольник слева-внизу(Ctrl+R) <br/>
**7.Как запустить код в режиме отладки?**<br/>
Нажать на зелёный треугольник слева внизу с изображением серого жука(F5)<br/>
**8.Как установить/убрать точку останова (breakpoint)?**<br/>
ЛКМ по полосе рядом с обозначением номера строки кода, чтобы поставить точку остановки и аналогичные действия, чтобы ее убрать <br/>
**9.Создайте программу со следующим кодом:**<br/>
```c++
#include <iostream>
int main() {
    int i;
    double d;
    i = 5;
    d = 5;
    std::cout << i << d;
    return 0;
}
```
В пятой строке i=0;<br/>
В шестой строке d=2.0500689e-316;<br/>
В седьмой строке i=d=5;<br/>
Значения не совпадают с MSVS.<br/>
**10.Закройте проект и перейдите на вкладку «Начало» => «Примеры»;**<br/>
**11.Выберите проект «Calculator Form Example». Для этого можно воспользоваться строкой поиска;**<br/>
**12.Изучите (по желанию) описание проекта в открывшемся окне;**<br/>
**13.Сейчас вы находитесь на вкладке «Проекты». Выберите комплект сборки. На рис. 1 присутствует только один комплект, но их может быть больше, например для сборки под Android или компилятором MSVS;**<br/>
**14.Перейдите на вкладку «Редактор» и запустите сборку проекта;**<br/>
**15.В инспекторе проекта выберите файл «main.cpp». В этом файле установите курсор на слово «show» в строке calculator.show(); и нажмите F1. Изучите справочную информацию. Таким же образом можно получить справку по любому объекту/методу/полю доступному в Qt;**<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_15.png?raw=true)<br/>Рис.1 Код файла "main.cpp", Справка "Show"<br/>
**16.В инспекторе проекта выберите файл «Формы» => «calculatorform.ui» и дважды счёлкните ЛКМ;**<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_16.1.png?raw=true)<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_16.2.png?raw=true)<br/>Рис.2 То, что открылость после двойного нажатия на «calculatorform.ui»<br/>
**17.Вы попали на вкладку «Дизайн». На форме замените английский текст на русский. Пересоберите проект.**<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_17.1.png?raw=true)<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_17.2.png?raw=true)<br/>Рис.3 Изменение ангийских слов на русские<br/>
![](https://github.com/NikitaGitHub19/githubkfu/blob/master/Lab7/Screenshots/Screenshot_17.3.png?raw=true)<br/>Рис.4 Собранный результат<br/>
**Вывод:** Я изучил основные возможности создания и отладки программ в IDE Qt Creator.
