#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>
/*
TODO
*���������� ��������� �������� ��� �������� � ����������� ���������
*������� �������� � ���������� � ��������� �������

*/
/*
���� ��������
*/

using namespace std;

bool AddConsoleTextColor(const string Text, const int Color = 7);//�����: 7 - �����(�����������), 10 - �������, 12 - �������, 14 - ������, 224 - ������ �� ������ ����
int ReadConsoleNum(const string Text = "", const int Color = 7);

string RuVigenereCipherEncrypt(const string Message, const string Key);
string RuViginereCipherDecrypt(const string EncryptedMessage, const string Key);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/**********************����****************************/
	//char FirstLetter = '�';
	//char LastLetter = '�';
	//cout << "FirstLetter: " << (int)FirstLetter << endl;//-32
	//cout << "LastLetter: " << (int)LastLetter << endl;//-1
	//
	//cout << "FirstLetter: " << (char)-34 << endl;
	//cout << "LastLetter: " << (char)-1 << endl;

	//for (int i = -32; i < 0; i++)
	//{
	//	cout << (char)i << endl;
	//}

	//cout << "Test: " << (int)'�' << endl;

	//cout << "n=" << (int)LastLetter - (int)FirstLetter << endl;
	/**********************����****************************/

	bool IsExit = false;
	string Message, Key;

	do {
		AddConsoleTextColor("���������� ��������� ������ ��������", 224);
		switch (ReadConsoleNum("��� ���������� ��������� ������� 1, ��� ����������� 2, ��� ������ 3...", 14))
		{
		case 1: 
		{
			AddConsoleTextColor("������� ���������...", 14);
			cin >> Message;
			AddConsoleTextColor("���� ��� �����...", 14);
			cin >> Key;
			AddConsoleTextColor("���������: " + RuVigenereCipherEncrypt(Message, Key), 14);
			break;
		}
		case 2:
		{
			AddConsoleTextColor("������� ������������� ���������...", 14);
			cin >> Message;
			AddConsoleTextColor("���� ��� �����...", 14);
			cin >> Key;
			string DecryptedMessage = RuViginereCipherDecrypt(Message, Key);
			AddConsoleTextColor("���������: " + RuViginereCipherDecrypt(Message, Key), 14);
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

	//AddConsoleTextColor("���������� ��������� ������ ��������", 224);
	//string Message, Key;// ���������� ��� ��������� � �����
	//AddConsoleTextColor("������� ���������...", 14);
	//cin >> Message;
	//AddConsoleTextColor("���� ��� �����...", 14);
	//cin >> Key;



	//int n = 32; //������ ��������
	//string EncryptedMessage = ""; //���������� ��� �������������� ���������
	//for (int i = 0; i < Message.length(); i++)//���� ����� ���������
	//{
	//	EncryptedMessage += (char)(((tolower((int)Message[i]) + 32 + tolower((int)Key[i % Key.length()]) + 32) % n) - 32);//��������� ��� �������� � ����� ������
	//}

	//AddConsoleTextColor("Message: " + Message);
	//AddConsoleTextColor("EncryptedMessage: " + EncryptedMessage);

	//string UnEncryptedMessage = ""; //���������� ��� ��������������� ���������
	//for (int i = 0; i < Message.length(); i++)
	//{
	//	UnEncryptedMessage += (char)(((tolower(EncryptedMessage[i]) + 32 - n - tolower((int)Key[i % Key.length()]) + 32) % n) - 32);
	//}
	//
	//AddConsoleTextColor("UnEncryptedMessage: " + UnEncryptedMessage);

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

string RuVigenereCipherEncrypt(const string Message, const string Key)
{
	int n = 32; //������ ��������
	string EncryptedMessage = ""; //���������� ��� �������������� ���������
	for (int i = 0; i < Message.length(); i++)//���� ����� ���������
	{
		EncryptedMessage += (char)(((tolower((int)Message[i]) + 32 + tolower((int)Key[i % Key.length()]) + 32) % n) - 32);//��������� ��� �������� � ����� ������
	}
	return EncryptedMessage;
}

string RuViginereCipherDecrypt(const string EncryptedMessage, const string Key)
{
	int n = 32; //������ ��������
	string UnEncryptedMessage = ""; //���������� ��� ��������������� ���������
	for (int i = 0; i < EncryptedMessage.length(); i++)
	{
		UnEncryptedMessage += (char)(((tolower(EncryptedMessage[i]) + 32 - n - tolower((int)Key[i % Key.length()]) + 32) % n) - 32);
	}

	return UnEncryptedMessage;
}
