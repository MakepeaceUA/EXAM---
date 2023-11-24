#include <iostream>
#include <cstring>
#include <ctime>
#include "Function.h"
#include <Windows.h>
using namespace std;

// Функция главного меню
void Menu()
{
    system("cls"); // Очищение консоли
    int choice; // Переменная для выбора
    
    cout << "\t\t\tМЕНЮ\n";
    cout << "1. Новая Игра\n";
    cout << "2. Выйти\n";
    cout << "\nВведите соответствующую цифру для выбора: ";
    cin >> choice; // Ввод
    switch (choice)
    {
    case 1:
    {
        while (true)
        {
            system("cls");  // Очищение консоли
            cout << "Выберите режим игры:\n";
            cout << "1. С игроком\n";
            cout << "2. C компьютером\n";
            cin >> choice; // Ввод
            system("cls");  // Очищение консоли
            if (choice == 1)
            {
                cout << "Вы выбрали режим с игроком.\n";
                Sleep(WAIT_TIME); // Ожидание
                GamePl(); // Переход в функцию игры с режимом "Игрок против Игрока"
                break;
            }
            else if (choice == 2)
            {
                cout << "Вы выбрали режим с компьютером.\n";
                Sleep(WAIT_TIME); // Ожидание
                GameAI();  // Переход в функцию игры с режимом "Игрок против ИИ"
                break;
            }
        }
    }
    case 2:
    {
        system("cls"); // Очищение консоли
        cout << "ВЫ ВЫШЛИ ИЗ ИГРЫ.";
        break;
    }
    default:
        Menu(); 
    }
}
// Функция создания игрового поля
void CreatField(char field[LENGTH][HEIGHT])
{

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < LENGTH; j++)
        {
            field[i][j] = '#';
        }
    }
}

// Функция режима игры "Игрок против Игрока"
void GamePl()
{
    system("cls"); // Очищение консоли
    
    char field[LENGTH][HEIGHT]; // Массив игрового поля
    int turn = 0; // Переменная для подсчёта ходов
   
    CreatField(field); // Создание игрового поля
    do
    {
        FirstPlayerTr(field); // Ход первого игрока
        turn++;
        EndGamePl(field, turn); // Проверка условий победы
        system("cls"); // Очищение консоли

        SecondPlayerTr(field); // Ход второго игрока
        turn++;
        EndGamePl(field, turn); // Проверка условий победы
        system("cls"); // Очищение консоли
    } while (true);
}
// Ход первого игрока
void FirstPlayerTr(char field[LENGTH][HEIGHT])
{
    int x, y; // переменные для координат
    do
    {
        cout << "Ход Игрока №1(крестики):\n";
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << field[i][j]; // Вывод игрового поля
            } 
            cout << "\n";
        }
        cout << "Введите позицию(x,y): ";
        cin >> x >> y;  // Ввод координат
        system("cls"); // Очищение консоли
    } while (x <= 0 || x > HEIGHT || y <= 0 || y > LENGTH || field[x - 1][y - 1] == 'x' || field[x - 1][y - 1] == 'o');
    field[x - 1][y - 1] = 'x';
}
// Ход второго игрока
void SecondPlayerTr(char field[LENGTH][HEIGHT])
{
    int x, y; // переменные для координат
    do
    {
        cout << "Ход Игрока №2(нолики):\n";
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << field[i][j]; // Вывод игрового поля
            }
            cout << "\n";
        }
        cout << "Введите позицию(x,y): ";
        cin >> x >> y; // Ввод координат
        system("cls"); // Очищение консоли
    } while (x <= 0 || x > HEIGHT || y <= 0 || y > LENGTH || field[x - 1][y - 1] == 'x' || field[x - 1][y - 1] == 'o');
    field[x - 1][y - 1] = 'o';
}
// Функция проверки условий победы
void EndGamePl(char field[LENGTH][HEIGHT], int turn)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        // Проверка победы игрока №1 по горизонтали и диагоналям
        if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'x') ||
            (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'x') ||
            (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'x') ||
            (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'x'))
        {
            cout << "Победа Игрока №1.\n"; Sleep(WAIT_TIME); system("cls");
            Menu(); // Переход в главное меню
        }
        // Проверка победы игрока №2 по горизонтали и диагоналям
        else if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'o') ||
            (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'o') ||
            (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'o') ||
            (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'o'))
        {
            cout << "Победа Игрока №2.\n"; Sleep(WAIT_TIME); system("cls");
            Menu(); // Переход в главное меню
        }
        // Проверка на ничью
        else if (turn == 9)
        {
            cout << "Ничья.\n"; Sleep(WAIT_TIME); system("cls");
            Menu(); // Переход в главное меню
        }
    }
}

// Функция режима игры "Игрок против ИИ"
void GameAI()
{
    system("cls"); // Очищение консоли
    int choice = 0; // Переменная выбора
    char field[LENGTH][HEIGHT]; // Массив игрового поля

    cout << "Выберите за что хотите играть:\n1:Крестики.\n2:Нолики\n";
    cin >> choice; // Ввод
    switch (choice)
    {
    case 1:
    {
        cout << "Ваш выбор:Крестики."; Sleep(WAIT_TIME); system("cls");
        break;
    }
    case 2:
    {
        cout << "Ваш выбор:Нолики."; Sleep(WAIT_TIME); system("cls");
        break;
    }
    default:
        GameAI();
    }
    int turn = 0; // Переменная для подсчёта ходов
    CreatField(field);
    do
    {
        // Проверка на то,играет ли игрок за крестики
        if (choice == 1)
        {
            PlayerTurn(field, choice); // Ход Игрока
            turn++;
            EndGameAI(field, choice, turn); // Проверка условий победы
            AITurn(field, choice); // Ход ИИ
            turn++;
            EndGameAI(field, choice, turn); // Проверка условий победы
        }
        // Проверка на то,играет ли игрок за крестики
        else if (choice == 2)
        {
            AITurn(field, choice); // Ход ИИ
            turn++;
            EndGameAI(field, choice, turn); // Проверка условий победы
            PlayerTurn(field, choice); // Ход Игрока
            turn++;
            EndGameAI(field, choice, turn); // Проверка условий победы
        }
        system("cls"); // Очищение консоли
    } while (true);
}
// Ход игрока
void PlayerTurn(char field[LENGTH][HEIGHT], int choice)
{
    int x, y; // Переменные координат
    do
    {
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << field[i][j]; // Вывод игрового поля
            }
            cout << "\n";
        }
        cout << "Введите позицию(x,y): ";
        cin >> x >> y; // Ввод координат
        system("cls"); // Очищение консоли
    } while (x <= 0 || x > HEIGHT || y <= 0 || y > LENGTH || field[x - 1][y - 1] == 'x' || field[x - 1][y - 1] == 'o');
    // Проверка на то,за что играет игрок(крестики или нолики)
    if (choice == 1)
        field[x - 1][y - 1] = 'x';
    if (choice == 2)
        field[x - 1][y - 1] = 'o';
}
// Ход ИИ
void AITurn(char field[LENGTH][HEIGHT], int choice)
{
    int x, y;
    do
    {
        x = rand() % 3; // Генерация случайной координаты x
        y = rand() % 3; // Генерация случайной координаты y
        system("cls"); // Очищение консоли
    } while (field[x][y] == 'x' || field[x][y] == 'o');
    // Проверка на то,за что играет игрок(крестики или нолики)
    if (choice == 1)
        field[x][y] = 'o';
    if (choice == 2)
        field[x][y] = 'x';
}
// Функция проверки условий победы
void EndGameAI(char field[LENGTH][HEIGHT], int choice, int turn)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        // Проверка на то,играет ли игрок за крестики
        if (choice == 1)
        {
            // Проверка победы Игрока по горизонтали и диагоналям
            if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'x') ||
                (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'x') ||
                (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'x') ||
                (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'x'))
            {
                cout << "Вы победили!\n"; Sleep(WAIT_TIME); system("cls");
                Menu(); // Переход в главное меню
            }
            // Проверка победы ИИ по горизонтали и диагоналям
            if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'o') ||
                (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'o') ||
                (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'o') ||
                (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'o'))
            {
                cout << "Вы проиграли.\n"; Sleep(WAIT_TIME); system("cls");
                Menu(); // Переход в главное меню
            }
        }
        // Проверка на то,играет ли игрок за нолики
        else if (choice == 2)
        {
            // Проверка победы ИИ по горизонтали и диагоналям
            if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'x') ||
                (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'x') ||
                (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'x') ||
                (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'x'))
            {
                cout << "Вы проиграли!\n"; Sleep(WAIT_TIME); system("cls");
                Menu();  // Переход в главное меню
            }
            // Проверка победы Игрока по горизонтали и диагоналям
            if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'o') ||
                (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'o') ||
                (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'o') ||
                (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'o'))
            {
                cout << "Вы победили!\n"; Sleep(WAIT_TIME); system("cls");
                Menu();  // Переход в главное меню
            }
        }
        // Проверка на ничью
        else if (turn == 9)
        {
            cout << "Ничья.\n"; Sleep(WAIT_TIME); system("cls");
            Menu(); // Переход в главное меню
        }
    }
}



int main()
{
    srand(time(0));
    setlocale(0, "RU");
    Menu();
}
