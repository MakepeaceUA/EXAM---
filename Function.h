#pragma once
#include <Windows.h>
using namespace std;
#define WAIT_TIME 2000
#define LENGTH 3
#define HEIGHT 3

void Menu();
void CreatField(char field[LENGTH][HEIGHT]);

void GamePl();
void FirstPlayerTr(char field[LENGTH][HEIGHT]);
void SecondPlayerTr(char field[LENGTH][HEIGHT]);
void EndGamePl(char field[LENGTH][HEIGHT],int turn);

void GameAI();
void PlayerTurn(char field[LENGTH][HEIGHT],int choice);
void AITurn(char field[LENGTH][HEIGHT], int choice);
void EndGameAI(char field[LENGTH][HEIGHT],int choce,int turn);





void Menu()
{
    system("cls");
    int choice;
    cout << "\t\t\tМЕНЮ\n";
    cout << "1. Новая Игра\n";
    cout << "2. Выйти\n";
    cout << "\nВведите соответствующую цифру для выбора: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        while (true) 
        {
            system("cls");
            cout << "Выберите режим игры:\n";
            cout << "1. С игроком\n";
            cout << "2. C компьютером\n";
            cin >> choice;
            system("cls");
            if (choice == 1)
            {
                cout << "Вы выбрали режим с игроком.\n";
                Sleep(WAIT_TIME);
                GamePl();
                break;
            }
            else if (choice == 2)
            {
                cout << "Вы выбрали режим с компьютером.\n";
                Sleep(WAIT_TIME);
                GameAI();
                break;
            }
        }
    }
    case 2:
    {
        system("cls");
        cout << "ВЫ ВЫШЛИ ИЗ ИГРЫ.";
        break;
    }
    default:
        Menu();
    }
}
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

void GamePl()
{
    system("cls");
    char field[LENGTH][HEIGHT];
    int turn = 0;
    CreatField(field);
    do
    {
        FirstPlayerTr(field);
        turn++;
        EndGamePl(field,turn);
        system("cls");

        SecondPlayerTr(field);
        turn++;
        EndGamePl(field,turn);
        system("cls");
    } while (true);
}
void FirstPlayerTr(char field[LENGTH][HEIGHT])
{
    int x, y;
    do
    {
        cout << "Ход Игрока №1(крестики):\n";
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << field[i][j];
            }
            cout << "\n";
        }
        cout << "Введите позицию(x,y): ";
        cin >> x >> y;
        system("cls");
    } while (x <= 0 || x > HEIGHT || y <= 0 || y > LENGTH || field[x - 1][y - 1] == 'x' || field[x - 1][y - 1] == 'o');
    field[x - 1][y - 1] = 'x';
}
void SecondPlayerTr(char field[LENGTH][HEIGHT])
{
    int x, y;
    do
    {
        cout << "Ход Игрока №2(нолики):\n";
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << field[i][j];
            }
            cout << "\n";
        }
        cout << "Введите позицию(x,y): ";
        cin >> x >> y;
        system("cls");
    } while (x <= 0 || x > HEIGHT || y <= 0 || y > LENGTH || field[x - 1][y - 1] == 'x' || field[x - 1][y - 1] == 'o');
    field[x - 1][y - 1] = 'o';
}
void EndGamePl(char field[LENGTH][HEIGHT], int turn)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'x') ||
            (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'x') ||
            (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'x') ||
            (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'x'))
        {
            cout << "Победа Игрока №1.\n"; Sleep(WAIT_TIME); system("cls");
            Menu();
        }
        else if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'o') ||
            (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'o') ||
            (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'o') ||
            (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'o'))
        {
            cout << "Победа Игрока №2.\n"; Sleep(WAIT_TIME); system("cls");
            Menu();
        }
        else if (turn == 9)
        {
            cout << "Ничья.\n"; Sleep(WAIT_TIME); system("cls");
            Menu();
        }
    }
}

void GameAI()
{
    system("cls");
    int choice = 0;
    char field[LENGTH][HEIGHT];

    cout << "Выберите за что хотите играть:\n1:Крестики.\n2:Нолики\n";
    cin >> choice;
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
    int turn = 0;
    CreatField(field);
    do
    {
        if (choice == 1) 
        {
            PlayerTurn(field, choice);
            turn++;
            EndGameAI(field, choice, turn);
            AITurn(field, choice);
            turn++;
            EndGameAI(field, choice, turn);
        }
        else if (choice == 2) 
        {
            AITurn(field, choice);
            turn++;
            EndGameAI(field, choice, turn);
            PlayerTurn(field, choice);
            turn++;
            EndGameAI(field, choice, turn);
        }
        system("cls");
    } while (true);
}
void PlayerTurn(char field[LENGTH][HEIGHT], int choice)
{
    int x, y;
    do
    {
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << field[i][j];
            }
            cout << "\n";
        }
        cout << "Введите позицию(x,y): ";
        cin >> x >> y;
        system("cls");
    } while (x <= 0 || x > HEIGHT || y <= 0 || y > LENGTH || field[x - 1][y - 1] == 'x' || field[x - 1][y - 1] == 'o');
    if (choice == 1)
        field[x - 1][y - 1] = 'x';
    if (choice == 2)
        field[x - 1][y - 1] = 'o';
}
void AITurn(char field[LENGTH][HEIGHT], int choice)
{
    int x, y;
    do
    {
        x = rand() % 3;
        y = rand() % 3;
        system("cls");
    } while (field[x][y] == 'x' || field[x][y] == 'o');
    if (choice == 1)
        field[x][y] = 'o';
    if (choice == 2)
        field[x][y] = 'x';
}
void EndGameAI(char field[LENGTH][HEIGHT], int choice, int turn)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        if (choice == 1)
        {
            if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'x') ||
                (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'x') ||
                (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'x') ||
                (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'x'))
            {
                cout << "Вы победили!\n"; Sleep(WAIT_TIME); system("cls");
                Menu();
            }
            if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'o') ||
                (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'o') ||
                (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'o') ||
                (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'o'))
            {
                cout << "Вы проиграли.\n"; Sleep(WAIT_TIME); system("cls");
                Menu();
            }
        }
        else if (choice == 2)
        {
            if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'x') ||
                (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'x') ||
                (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'x') ||
                (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'x'))
            {
                cout << "Вы проиграли!\n"; Sleep(WAIT_TIME); system("cls");
                Menu();
            }
            if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'o') ||
                (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'o') ||
                (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'o') ||
                (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'o'))
            {
                cout << "Вы победили!\n"; Sleep(WAIT_TIME); system("cls");
                Menu();
            }
        }
        else if (turn == 9)
        {
            cout << "Ничья.\n"; Sleep(WAIT_TIME); system("cls");
            Menu();
        }
    }
}
