#include "pch.h"

using namespace System;

int main(array<System::String^>^ args)
{
    Console::OutputEncoding = System::Text::Encoding::UTF8;
    Console::InputEncoding = System::Text::Encoding::UTF8;

    Console::Write("Введіть вихідний рядок: ");
    String^ originalString = Console::ReadLine();

    array<Char>^ charArray = originalString->ToCharArray();

    Array::Reverse(charArray);

    String^ reversedString = gcnew String(charArray);

    Console::WriteLine("\nОтриманий новий рядок:");
    Console::WriteLine(reversedString);

    Console::ReadLine();
    return 0;
}
