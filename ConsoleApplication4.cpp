#include "pch.h"

using namespace System;

int main(array<System::String^>^ args)
{
    Console::OutputEncoding = System::Text::Encoding::UTF8;

    // 1. Введення розмірів матриці
    Console::Write("Введіть кількість рядків (N): ");
    int N = Convert::ToInt32(Console::ReadLine());

    Console::Write("Введіть кількість стовпців (M): ");
    int M = Convert::ToInt32(Console::ReadLine());

    // Створюємо матрицю NxM
    array<int, 2>^ matrix = gcnew array<int, 2>(N, M);

    // Додатковий масив для зберігання мінімумів кожного рядка
    // Це потрібно, щоб не шукати мінімум заново при кожному порівнянні
    array<int>^ minInRow = gcnew array<int>(N);

    Console::WriteLine("\nВведіть елементи матриці:");

    for (int i = 0; i < N; i++) {
        int currentMin = Int32::MaxValue; // Початкове значення мінімуму

        for (int j = 0; j < M; j++) {
            Console::Write("A[{0}][{1}] = ", i, j);
            matrix[i, j] = Convert::ToInt32(Console::ReadLine());

            // Одразу шукаємо мінімум у цьому рядку
            if (matrix[i, j] < currentMin) {
                currentMin = matrix[i, j];
            }
        }
        // Записуємо знайдений мінімум для рядка i
        minInRow[i] = currentMin;
        Console::WriteLine("  -> Мін. елемент цього рядка: " + currentMin);
    }

    Console::WriteLine("\n--- Початкова матриця ---");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Console::Write("{0, 5}", matrix[i, j]);
        }
        Console::WriteLine();
    }

    // Сортування рядків
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {

            if (minInRow[j] > minInRow[j + 1]) {

                // А. Міняємо значення в масиві мінімумів
                int tempMin = minInRow[j];
                minInRow[j] = minInRow[j + 1];
                minInRow[j + 1] = tempMin;

                // Б. Міняємо місцями САМІ РЯДКИ в матриці (поелементно)
                for (int k = 0; k < M; k++) {
                    int tempVal = matrix[j, k];
                    matrix[j, k] = matrix[j + 1, k];
                    matrix[j + 1, k] = tempVal;
                }
            }
        }
    }

    // 4. Виведення результату
    Console::WriteLine("\n Відсортована матриця");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Console::Write("{0, 5}", matrix[i, j]);
        }
        // Додатково виведемо мінімум, щоб було видно, що сортування правильне
        Console::WriteLine("   (мін: {0})", minInRow[i]);
    }

    Console::ReadLine();
    return 0;
}