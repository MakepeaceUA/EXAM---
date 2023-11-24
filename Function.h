#pragma once
#include <Windows.h>
using namespace std;
#define WAIT_TIME 2000 // Время ожидания
#define LENGTH 3 // Длина игрового поля
#define HEIGHT 3 // Высота игрового поля

void Menu(); // Функция главного меню
void CreatField(char field[LENGTH][HEIGHT]); // Функция создания игрового поля

void GamePl(); // Функция режима игры "Игрок против Игрока"
void FirstPlayerTr(char field[LENGTH][HEIGHT]); // Ход первого игрока
void SecondPlayerTr(char field[LENGTH][HEIGHT]); // Ход второго игрока
void EndGamePl(char field[LENGTH][HEIGHT],int turn); // Функция проверки условий победы

void GameAI();// Функция режима игры "Игрок против ИИ"
void PlayerTurn(char field[LENGTH][HEIGHT],int choice); // Ход игрока
void AITurn(char field[LENGTH][HEIGHT], int choice); // Ход ИИ
void EndGameAI(char field[LENGTH][HEIGHT],int choce,int turn); // Функция проверки условий победы

