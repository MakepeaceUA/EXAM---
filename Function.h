#pragma once
#include <Windows.h>
using namespace std;
#define WAIT_TIME 2000
#define LENGTH 3
#define HEIGHT 3
enum GameMode { PlayerMod = 1, AIMod = 2 };


void GamePl();
void FirstPlayerTr(char field[LENGTH][HEIGHT]);
void SecondPlayerTr(char field[LENGTH][HEIGHT]);
void EndGamePl(char field[LENGTH][HEIGHT],int turn);

void GameAI();
void PlayerTurn(char field[LENGTH][HEIGHT],int choice);
void AITurn(char field[LENGTH][HEIGHT], int choice);
void EndGameAI(char field[LENGTH][HEIGHT],int choce,int turn);


void Menu();
void CreatField(char field[LENGTH][HEIGHT]);




void EndGamePl(char field[LENGTH][HEIGHT], int turn)
{
    for (int i = 0; i < HEIGHT; i++)
    {
        if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'x') ||
            (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'x') ||
            (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'x') ||
            (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'x'))
        {
            cout << "������ ������ �1.\n"; Sleep(WAIT_TIME); system("cls");
            Menu();
        }
        else if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'o') ||
            (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'o') ||
            (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'o') ||
            (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'o'))
        {
            cout << "������ ������ �2.\n"; Sleep(WAIT_TIME); system("cls");
            Menu();
        }
        else if (turn == 9)
        {
            cout << "�����.\n"; Sleep(WAIT_TIME); system("cls");
            Menu();
        }
    }
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
                cout << "�� ��������!\n"; Sleep(WAIT_TIME); system("cls");
                Menu();
            }
            if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'o') ||
                (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'o') ||
                (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'o') ||
                (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'o'))
            {
                cout << "�� ���������.\n"; Sleep(WAIT_TIME); system("cls");
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
                cout << "�� ���������!\n"; Sleep(WAIT_TIME); system("cls");
                Menu();
            }
            if ((field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] == 'o') ||
                (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] == 'o') ||
                (field[0][0] == field[1][1] && field[1][1] == field[2][2] && field[0][0] == 'o') ||
                (field[0][2] == field[1][1] && field[1][1] == field[2][0] && field[0][2] == 'o'))
            {
                cout << "�� ��������!\n"; Sleep(WAIT_TIME); system("cls");
                Menu();
            }
        }
        else if (turn == 9)
        {
            cout << "�����.\n"; Sleep(WAIT_TIME); system("cls");
            Menu();
        }
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
void Menu()
{
    int choice;
    cout << "\t\t\t����\n";
    cout << "1. ����� ����\n";
    cout << "2. �����\n";
    cout << "\n������� ��������������� ����� ��� ������: ";
    cin >> choice;
    Sleep(WAIT_TIME); system("cls");
    switch (choice)
    {
    case 1:
    {
        cout << "�������� ����� ����:\n";
        cout << "1. � �������\n";
        cout << "2. C �����������\n";
        cin >> choice;
        if (choice == PlayerMod)
        {
            cout << "�� ������� ����� � �������.\n";
            Sleep(WAIT_TIME);
            GamePl();
            break;
        }
        else if (choice == AIMod)
        {
            cout << "�� ������� ����� � �����������.\n";
            Sleep(WAIT_TIME);
            GameAI();
            break;
        }
        else
        {
            cout << "������.";
            break;
        }
    }
    case 2:
    {
        cout << "�� ����� �� ����.";
        break;
    }
    default:
        cout << "������.";
    }
}

void FirstPlayerTr(char field[LENGTH][HEIGHT])
{
    int x, y;
    do
    {
        cout << "��� ������ �1(��������):\n";
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << field[i][j];
            }
            cout << "\n";
        }
        cout << "������� �������(x,y): ";
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
        cout << "��� ������ �2(������):\n";
        for (int i = 0; i < HEIGHT; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << field[i][j];
            }
            cout << "\n";
        }
        cout << "������� �������(x,y): ";
        cin >> x >> y;
        system("cls");
    } while (x <= 0 || x > HEIGHT || y <= 0 || y > LENGTH || field[x - 1][y - 1] == 'x' || field[x - 1][y - 1] == 'o');
    field[x - 1][y - 1] = 'o';
}
void AITurn(char field[LENGTH][HEIGHT],int choice)
{
    int x, y;
    do
    {
        x = rand() % 3;
        y = rand() % 3;
        system("cls");
    } while (field[x][y] == 'x' || field[x][y] == 'o');
    if(choice == 1)
        field[x][y] = 'o';
    if(choice == 2)
        field[x][y] = 'x';
}
void PlayerTurn(char field[LENGTH][HEIGHT],int choice) 
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
        cout << "������� �������(x,y): ";
        cin >> x >> y;
        system("cls");
    } while (x <= 0 || x > HEIGHT || y <= 0 || y > LENGTH || field[x - 1][y - 1] == 'x' || field[x - 1][y - 1] == 'o');
    if (choice == 1)
        field[x - 1][y - 1] = 'x';
    if (choice == 2) 
        field[x - 1][y - 1] = 'o';
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
void GameAI()
{
    system("cls");
    int choice;
    char field[LENGTH][HEIGHT];

    cout << "�������� �� ��� ������ ������:\n1:��������.\n2:������\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "��� �����:��������."; Sleep(WAIT_TIME); system("cls");
        break;
    }
    case 2:
    {
        cout << "��� �����:������."; Sleep(WAIT_TIME); system("cls");
        break;
    }
    }
    int turn = 0;
    CreatField(field);
    do
    {
        PlayerTurn(field, choice);
        turn++;
        EndGameAI(field, choice, turn);
        
        AITurn(field,choice);
        turn++;
        EndGameAI(field, choice, turn);
        system("cls");
    } while (true);
}
