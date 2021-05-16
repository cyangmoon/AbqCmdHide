#include<Windows.h>
#include<iostream>

using namespace std;

HWND hWinHide;
HWND hWin;

DWORD WINAPI MyStartAbaqus(LPVOID lpParam);
VOID MyFindAbaqusWindows();

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPreInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	MyFindAbaqusWindows();
	if (IsWindowVisible(hWin) && IsWindowVisible(hWinHide)) {
		ShowWindow(hWinHide, SW_HIDE);
		return 0;
	}
	CreateThread(NULL, 0, MyStartAbaqus, NULL, 0, NULL);
	while (true) {
		MyFindAbaqusWindows();
		if (IsWindowVisible(hWin)) {
			if (IsWindowVisible(hWinHide)) {
				ShowWindow(hWinHide, SW_HIDE);
				return 0;
			}
			Sleep(200);
		}
	}
}

VOID MyFindAbaqusWindows()
{
	hWinHide = FindWindow(0, L"Abaqus CAE");
	if (hWinHide == NULL) {
		hWinHide = FindWindow(0, L"Administrator:  Abaqus CAE");
		if (hWinHide == NULL) {
			hWinHide = FindWindow(0, L"����Ա:  Abaqus CAE");
		}
	}
	hWin = FindWindow(0, L"Abaqus/CAE 2021 [Viewport: 1]");
	if (hWin == NULL) {
		hWin = FindWindow(0, L"Abaqus/CAE 6.14-4 [Viewport: 1]");
		if (hWin == NULL) {
			hWin = FindWindow(0, L"Abaqus/CAE 2020 [Viewport: 1]");
			if (hWin == NULL) {
				hWin = FindWindow(0, L"Abaqus/CAE 2019 [Viewport: 1]");
				if (hWin == NULL) {
					hWin = FindWindow(0, L"Abaqus/CAE 2018 [Viewport: 1]");
					if (hWin == NULL) {
						hWin = FindWindow(0, L"Abaqus/CAE 2017 [Viewport: 1]");
						if (hWin == NULL) {
							hWin = FindWindow(0, L"Abaqus/CAE 2016 [Viewport: 1]");
							if (hWin == NULL) {
								hWin = FindWindow(0, L"Abaqus/CAE 6.14-1 [Viewport: 1]");
								if (hWin == NULL) {
									hWin = FindWindow(0, L"Abaqus/CAE 6.14-2 [Viewport: 1]");
									if (hWin == NULL) {
										hWin = FindWindow(0, L"Abaqus/CAE 6.14-3 [Viewport: 1]");
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return VOID();
}

DWORD WINAPI MyStartAbaqus(LPVOID lpParam)
{
	char openAbqCommand[] = "title Abaqus CAE&& abaqus cae";
	system(openAbqCommand);
	/*if (system(openAbqCommand)) {
		cout << "�Ƿ�װabaqus�����Ѿ���װ�������Ƿ񽫰�װĿ¼�µ�command�ļ���Ŀ¼����������������þ�����������аٶȣ�";
	}*/
	return 0;
}
