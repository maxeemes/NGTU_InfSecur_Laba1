#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>
/*
TODO
*переделать нумерацию символов при шифровке и расшифровке сообщений
*вынести шифровку и дешифровку в отдельные функции

*/
/*
Шифр Вижинера
*/

using namespace std;

bool AddConsoleTextColor(const string Text, const int Color = 7);//Цвета: 7 - белый(стандартный), 10 - зеленый, 12 - красный, 14 - желтый, 224 - черный на желтом фоне
int ReadConsoleNum(const string Text = "", const int Color = 7);

string RuVigenereCipherEncrypt(const string Message, const string Key);
string RuViginereCipherDecrypt(const string EncryptedMessage, const string Key);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/**********************ТЕСТ****************************/
	//char FirstLetter = 'а';
	//char LastLetter = 'я';
	//cout << "FirstLetter: " << (int)FirstLetter << endl;//-32
	//cout << "LastLetter: " << (int)LastLetter << endl;//-1
	//
	//cout << "FirstLetter: " << (char)-34 << endl;
	//cout << "LastLetter: " << (char)-1 << endl;

	//for (int i = -32; i < 0; i++)
	//{
	//	cout << (char)i << endl;
	//}

	//cout << "Test: " << (int)'ё' << endl;

	//cout << "n=" << (int)LastLetter - (int)FirstLetter << endl;
	/**********************ТЕСТ****************************/

	bool IsExit = false;
	string Message, Key;

	do {
		AddConsoleTextColor("Шифрование сообщений шифром Вижинера", 224);
		switch (ReadConsoleNum("Для шифрования сообщения введите 1, для расшифровки 2, для выхода 3...", 14))
		{
		case 1: 
		{
			AddConsoleTextColor("Введите сообщение...", 14);
			cin >> Message;
			AddConsoleTextColor("Ключ для шифра...", 14);
			cin >> Key;
			AddConsoleTextColor("Результат: " + RuVigenereCipherEncrypt(Message, Key), 14);
			break;
		}
		case 2:
		{
			AddConsoleTextColor("Введите зашифрованное сообщение...", 14);
			cin >> Message;
			AddConsoleTextColor("Ключ для шифра...", 14);
			cin >> Key;
			string DecryptedMessage = RuViginereCipherDecrypt(Message, Key);
			AddConsoleTextColor("Результат: " + RuViginereCipherDecrypt(Message, Key), 14);
			break;
		}
		case 3:
		{
			IsExit = true;
			break;
		}
		default:
			break;
		}
	} while (IsExit == false);

	//AddConsoleTextColor("Шифрование сообщений шифром Вижинера", 224);
	//string Message, Key;// переменные для сообщения и ключа
	//AddConsoleTextColor("Введите сообщение...", 14);
	//cin >> Message;
	//AddConsoleTextColor("Ключ для шифра...", 14);
	//cin >> Key;



	//int n = 32; //размер алфавита
	//string EncryptedMessage = ""; //переменная для зашифрованного сообщения
	//for (int i = 0; i < Message.length(); i++)//цикл шифра сообщения
	//{
	//	EncryptedMessage += (char)(((tolower((int)Message[i]) + 32 + tolower((int)Key[i % Key.length()]) + 32) % n) - 32);//исправить для символов в конце списка
	//}

	//AddConsoleTextColor("Message: " + Message);
	//AddConsoleTextColor("EncryptedMessage: " + EncryptedMessage);

	//string UnEncryptedMessage = ""; //переменная для расшифрованного сообщения
	//for (int i = 0; i < Message.length(); i++)
	//{
	//	UnEncryptedMessage += (char)(((tolower(EncryptedMessage[i]) + 32 - n - tolower((int)Key[i % Key.length()]) + 32) % n) - 32);
	//}
	//
	//AddConsoleTextColor("UnEncryptedMessage: " + UnEncryptedMessage);

	return 0;
}

bool AddConsoleTextColor(const string Text, const int Color)//Цвета: 7 - белый(стандартный), 10 - зеленый, 12 - красный, 14 - желтый, 224 - черный на желтом фоне
{
	if (Color == 7) {
		cout << Text << endl;
	}
	else {
		HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(Console, Color);
		cout << Text << endl;
		SetConsoleTextAttribute(Console, 7);
	}
	return true;
}

int ReadConsoleNum(const string Text, const int Color)
{
	if (!Text.empty())
	{
		AddConsoleTextColor(Text, Color);
	}
	int Num;
	cin >> Num;
	if (Num >= 0)
	{
		return Num;
	}
	return -1;
}

string RuVigenereCipherEncrypt(const string Message, const string Key)
{
	int n = 32; //размер алфавита
	string EncryptedMessage = ""; //переменная для зашифрованного сообщения
	for (int i = 0; i < Message.length(); i++)//цикл шифра сообщения
	{
		EncryptedMessage += (char)(((tolower((int)Message[i]) + 32 + tolower((int)Key[i % Key.length()]) + 32) % n) - 32);//исправить для символов в конце списка
	}
	return EncryptedMessage;
}

string RuViginereCipherDecrypt(const string EncryptedMessage, const string Key)
{
	int n = 32; //размер алфавита
	string UnEncryptedMessage = ""; //переменная для расшифрованного сообщения
	for (int i = 0; i < EncryptedMessage.length(); i++)
	{
		UnEncryptedMessage += (char)(((tolower(EncryptedMessage[i]) + 32 - n - tolower((int)Key[i % Key.length()]) + 32) % n) - 32);
	}

	return UnEncryptedMessage;
}
