#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>
/*
���� ��������
*/

using namespace std;

bool AddConsoleTextColor(const string Text, const int Color = 7);//�����: 7 - �����(�����������), 10 - �������, 12 - �������, 14 - ������, 224 - ������ �� ������ ����
int ReadConsoleNum(const string Text = "", const int Color = 7);

int RuSymbolsCount(const string Text);
string RuVigenereCipherEncrypt(const string Message, const string Key);
string RuViginereCipherDecrypt(const string EncryptedMessage, const string Key);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//���������� �������� ����������
	bool IsExit = false;
	string Message, Key;

	//���������� ���� ���������
	do {
		AddConsoleTextColor("���������� ��������� ������ ��������", 224);
		switch (ReadConsoleNum("��� ���������� ��������� ������� 1, ��� ����������� 2, ��� ������ 3...", 14))
		{
		case 1: 
		{
			AddConsoleTextColor("������� ���������...", 14);
			//cin >> Message;
			getchar();
			getline(cin, Message);
			AddConsoleTextColor("���� ��� �����...", 14);
			//cin >> Key;
			getline(cin, Key);
			if (Key.length() == RuSymbolsCount(Key) && Key.length() > 0)
			{
				AddConsoleTextColor("���������: " + RuVigenereCipherEncrypt(Message, Key), 14);
			}
			else
			{
				AddConsoleTextColor("������ ����������� ����! ���� ������ �� ���� ������ � ������ �������� ������ �� �������� �������� �������� ��� ����� ""�"" � ��������!", 12);
			}
			break;
		}
		case 2:
		{
			AddConsoleTextColor("������� ������������� ���������...", 14);
			//cin >> Message;
			getchar();
			getline(cin, Message);
			AddConsoleTextColor("���� ��� �����...", 14);
			//cin >> Key;
			getline(cin, Key);
			if (Key.length() == RuSymbolsCount(Key) && Key.length() > 0)
			{
				AddConsoleTextColor("���������: " + RuViginereCipherDecrypt(Message, Key), 14);
			}
			else
			{
				AddConsoleTextColor("������ ����������� ����! ���� ������ �� ���� ������ � ������ �������� ������ �� �������� �������� �������� ��� ����� ""�"" � ��������!", 12);
			}
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

	return 0;
}

bool AddConsoleTextColor(const string Text, const int Color)//�����: 7 - �����(�����������), 10 - �������, 12 - �������, 14 - ������, 224 - ������ �� ������ ����
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

int RuSymbolsCount(const string Text)
{
	int Count = 0;
	for (int i = 0; i < Text.length(); i++)
	{
		Count += tolower(Text[i]) >= -32 && tolower(Text[i]) <= -1;
	}
	return Count;
}

string RuVigenereCipherEncrypt(const string Message, const string Key)
{
	int n = 32; //������ ��������
	string EncryptedMessage = ""; //���������� ��� �������������� ���������
	for (int i = 0, RUi = 0; i < Message.length(); i++)//���� ����� ���������
	{
		if (tolower(Message[i]) >= -32 && tolower(Message[i]) <= -1)
		{
			EncryptedMessage += (char)(((tolower(Message[i]) + 32 + tolower(Key[RUi % Key.length()]) + 32) % n) - 32);
			RUi++;
		}
		else
		{
			EncryptedMessage += (char)(tolower(Message[i]));
		}
	}
	return EncryptedMessage;
}

string RuViginereCipherDecrypt(const string EncryptedMessage, const string Key)
{
	int n = 32; //������ ��������
	string UnEncryptedMessage = ""; //���������� ��� ��������������� ���������
	for (int i = 0, RUi = 0; i < EncryptedMessage.length(); i++)
	{
		if (tolower(EncryptedMessage[i]) >= -32 && tolower(EncryptedMessage[i]) <= -1)
		{
			UnEncryptedMessage += (char)(((tolower(EncryptedMessage[i]) + 32 - n - tolower(Key[RUi % Key.length()]) + 32) % n) - 32);
			RUi++;
		}
		else
		{
			UnEncryptedMessage += (char)(tolower(EncryptedMessage[i]));
		}
	}

	return UnEncryptedMessage;
}
