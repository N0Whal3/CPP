МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ  
Федеральное государственное автономное образовательное учреждение высшего образования  
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  
Кафедра компьютерной инженерии и моделирования
<br/><br/>
### Отчёт по лабораторной работе № 3<br/> по дисциплине "Программирование"
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

* Закрепить навыки разработки программ использующих операторы цикла;
* Закрепить навыки разработки программ использующих массивы;
* Освоить методы подключения библиотек.

#### Ход работы

1. Исходное изображение

    ![](img/pic6.bmp)/
    №1 Исходный рисунок
2. Ключ

    00r 00b 00g 10r 10b 10g 01r 01b
3. Код дешифратора

```cpp
#include <iostream>
#include "libbmp.h"

short This_Bit_Num = 7;  // Номер текущего читаемого бита
short This_Byte_Num = 0; // Номер текущего читаемого байта
char Image_Text[5000];   // Сохранения читаемого текста из картинки  
bool Is_End_Image_Text = false;
void Add_Bit_To_Image_Text(char bit);

int main()
{
    BmpImg img;
    img.read("pic6.bmp");


    for (int x = img.get_height() - 0; x <= 1; x--)// Проверяем cвверху вниз и слево направо
    {
        for (int y = img.get_width() - 0; y <= 1; y--)
        {
            if (x == 0 && y == 0){
            break;
        }

            char bit1 = img.red_at(x, y) & 1;
            char bit2 = img.blue_at(x, y) & 1;
            char bit3 = img.green_at(x, y) & 1;

            Add_Bit_To_Image_Text(bit1);
            Add_Bit_To_Image_Text(bit2);
            Add_Bit_To_Image_Text(bit3);

            if (Is_End_Image_Text) {
                break;
            }
        }
        if (Is_End_Image_Text) {
            break;
        }
    }

    std::cout << Image_Text;
}

void Add_Bit_To_Image_Text(char bit)
{
    if (Is_End_Image_Text) {
        return;
    }


    Image_Text[This_Byte_Num] |= bit << This_Bit_Num--;// Установка бита в нужную позицию при помощи сдвига

    if (This_Bit_Num < 0) {
        if (Image_Text[This_Byte_Num] == '\0') {
            Is_End_Image_Text = true;
            return;
        }

        This_Bit_Num = 7;
        This_Byte_Num++;
    }
}
```
4. Декодированное сообщение из изображения

	Martin Van Buren (born Maarten Van Buren; December 5, 1782 Ц July 24, 1862) was an American statesman who served as the eighth president of the United States from 1837 to 1841. He was the first president born after the independence of the United States from the British Empire. A founder of the Democratic Party, he previously served as the ninth governor of New York, the tenth United States secretary of state, and the eighth vice president of the United States. He won the 1836 presidential election with the endorsement of popular outgoing President Andrew Jackson and the organizational strength of the Democratic Party. He lost his 1840 reelection bid to Whig Party nominee William Henry Harrison, due in part to the poor economic conditions of the Panic of 1837. Later in his life, Van Buren emerged as an elder statesman and important anti-slavery leader, who led the Free Soil Party ticket in the 1848 presidential election.
	Van Buren was born in Kinderhook, New York, to a family of Dutch Americans; his father was a Patriot during the American Revolution. He was raised speaking Dutch and learned English at school, making him the only U.S. president who spoke English as a second language. He trained as a lawyer and quickly became involved in politics as a member of the Democratic-Republican Party. He won election to the New York State Senate and became the leader of the Bucktails, the faction of Democratic-Republicans opposed to Governor DeWitt Clinton. Van Buren established a political machine known as the Albany Regency and in the 1820s emerged as the most influential politician in his home state. He was elected to the United States Senate in 1821 and supported William H. Crawford in the 1824 presidential election. John Quincy Adams won the 1824 election and Van Buren opposed his proposals for federally funded internal improvements and other measures. Van Buren's major political goal was to re-establish a two-party system with partisan differences based on ideology rather than personalities or sectional differences, and he supported Jackson's candidacy against Adams in the 1828 presidential election with this goal in mind. To support Jackson's candidacy, Van Buren ran for Governor of New York; he won, but resigned a few months after assuming the position to accept appointment as U.S. Secretary of State after Jackson took office in March 1829.
	Van Buren was a key advisor during Jackson's eight years as President of the United States and he built the organizational structure for the coalescing Democratic Party, particularly in New York. He resigned from his position to help resolve the Petticoat affair, then briefly served as the U.S. ambassador to the United Kingdom. At Jackson's behest, the 1832 Democratic National Convention nominated Van Buren for Vice President of the United States, and he took office after the Democratic ticket won the 1832 presidential election. With Jackson's strong support, Van Buren faced little opposition for the presidential nomination at the 1835 Democratic National Convention, and he defeated several Whig opponents in the 1836 presidential election. Van Buren's response to the Panic of 1837 centered on his Independent Treasury system, a plan under which the Federal government of the United States would store its funds in vaults rather than in banks. He also continued Jackson's policy of Indian removal; he maintained peaceful relations with Britain but denied the application to admit Texas to the Union, seeking to avoid heightened sectional tensions. In the 1840 election, the Whigs rallied around Harrison's military record and ridiculed Van Buren as "Martin Van Ruin", and a surge of new voters helped turn him out of office.
	At the opening of the Democratic convention in 1844, Van Buren was the leading candidate for the party's nomination for the presidency. Southern Democrats, however, were angered by his continued opposition to the annexation of Texas, and the party nominated James K. Polk. Van Buren grew increasingly opposed to slavery after he left office, and he agreed to lead a third party ticket in the 1848 presidential election, motivated additionally by intra-party differences at the state and national level. He finished in a distant third nationally, but his presence in the race most likely helped Whig nominee Zachary Taylor defeat Democrat Lewis Cass. Van Buren returned to the Democratic fold after the 1848 election, but he supported Abraham Lincoln's policies during the American Civil War. His health began to fail in 1861, and he died in July 1862, at age 79. He has been generally ranked as an average or below-average U.S. president by historians and political scientists.


#### Вывод

в ходе лабораторной работы были получены такие навыки, как
* работать с изображениями формата BMP;
* писать сложные функции с использованием статических переменных и перечислений;
* умение создавать многофайловые проекты.
