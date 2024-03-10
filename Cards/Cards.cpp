#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;

int main()
{
    setlocale(0, "");
    printf("\033[3%d;4%dm", 7, 5);
    cout << "Нажми 'Enter' чтобы начать игру!";
    cin.get();
    system("cls");
    Sleep(500);
    int aper[10];
    string kart[10] = { "1","2","3","4","5","6","7","8","9","10" };
    srand(time(NULL));

    int indexi[10] = { 0,1,2,3,4,5,6,7,8,9 };

    random_shuffle(begin(indexi), end(indexi)); // получаем список из 10 чисел, для случайных карточек

    for (int i = 0, qount = 1; i < 10; i += 2) {
        aper[indexi[i]] = qount;
        aper[indexi[i + 1]] = qount;
        qount++;
    }

    //1 - !
    //2 - @
    //3 - #
    //4 - $
    //5 - %
    // 0 - Пробел

    int znach = 10;
    int v1, v2;
    while (znach != 0) {
        cout << "Игра найди пару!" << endl << endl;
        for (int i = 0; i < 10; i++) {
            cout << "[" << kart[i] << "] ";
        }
        cout << endl;
        Sleep(400);
        cout << endl << "Выбери две карточки!" << endl << endl;
        cin >> v1 >> v2;
        v1--;
        v2--;
        system("cls");
        string ch;
        cout << "Игра найди пару!";
        cout << endl << endl;
        for (int i = 0; i < 10; i++) {
            if (i == v1 or i == v2)
            {
                switch (aper[i]) {
                case 1:
                    ch = "!";
                    break;
                case 2:
                    ch = "@";
                    break;
                case 3:
                    ch = "#";
                    break;
                case 4:
                    ch = "$";
                    break;
                case 5:
                    ch = "%";
                    break;
                default:
                    ch = ' ';
                    break;
                }
                cout << "[" << ch << "] ";
            }
            else
            {
                cout << "[" << kart[i] << "] ";
            }
        }
        Sleep(4000);
        if (aper[v1] == aper[v2])
        {
            kart[v1] = " ";
            kart[v2] = " ";
            znach = znach - 2;
        }
        cout << endl << endl;
        system("cls");
    }
    cout << "Ты выиграл, поздравляю!" << endl << endl;
    printf("\033[00m");
    cin.get();
    return 0;
}