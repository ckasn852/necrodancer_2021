#include "stdafx.h"
#include "Cmouse.h"

Cmouse::Cmouse(HWND handle)
	:handle(handle),position(0,0)
	,wheelValue(0),wheelPrevValue(0),wheelMoveValue(0)
{
	ZeroMemory(buttonStatus, sizeof(byte) * 8);//destination, 크기  >> (포인터의)값을 0으로 초기화 , memset, ={0} 로도 가능?>> struct는 가능함 딴놈은 몰라
	ZeroMemory(buttonPrevStatus, sizeof(byte) * 8);
	ZeroMemory(buttonMap, sizeof(byte) * 8);

	ZeroMemory(buttonCount, sizeof(int) * 8);
	
	doubleClickTime = GetDoubleClickTime();
	startDoubleClickTime[0] = GetTickCount();

	for (int i = 1; i < 8; i++)
		startDoubleClickTime[i] = startDoubleClickTime[0];
}

Cmouse::~Cmouse()
{
}

void Cmouse::WndProc(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	if (iMessage == WM_MOUSEMOVE)
	{
		position.x = (float)LOWORD(lParam);
		position.y = (float)HIWORD(lParam);
	}

	if (iMessage == WM_MOUSEWHEEL)
	{
		short temp = (short)HIWORD(wParam);

		wheelPrevValue = wheelValue;
		wheelValue += (float)temp;
	}
}

void Cmouse::Update()
{
	memcpy(buttonPrevStatus, buttonStatus, sizeof(byte) * 8);
	ZeroMemory(buttonStatus, sizeof(byte) * 8);
	ZeroMemory(buttonMap, sizeof(byte) * 8);

	buttonStatus[0] = GetAsyncKeyState(VK_LBUTTON) & 0x8000 ? 1 : 0;
	buttonStatus[1] = GetAsyncKeyState(VK_RBUTTON) & 0x8000 ? 1 : 0;
	buttonStatus[2] = GetAsyncKeyState(VK_MBUTTON) & 0x8000 ? 1 : 0;

	for (UINT i = 0; i < 8; i++)
	{
		byte prevStatus = buttonPrevStatus[i];
		byte status = buttonStatus[i];

		if (prevStatus == 0 && status == 1)
			buttonMap[i] = Button::Down;
		else if (prevStatus == 1 && status == 0)
			buttonMap[i] = Button::Up;
		else if (prevStatus == 1 && status == 1)
			buttonMap[i] = Button::Press;
		else
			buttonMap[i] = Button::None;
	}
	UINT buttonStatus = GetTickCount();
	for (UINT i = 0; i < 8; i++)
	{
		if (buttonMap[i] == Button::Down)
		{
			if (buttonCount[i] == 1)
			{
				if (buttonStatus - startDoubleClickTime[i] >= doubleClickTime)
					buttonCount[i] = 0;
			}
			buttonCount[i]++;

			if (buttonCount[i] == 1)
				startDoubleClickTime[i] = buttonStatus;
		}

		if (buttonMap[i] == Button::Up)
		{
			if (buttonCount[i] == 1)
			{
				if (buttonStatus - startDoubleClickTime[i] >= doubleClickTime)
					buttonCount[i] = 0;
			}
			else if (buttonCount[i] == 2)
			{
				if (buttonStatus - startDoubleClickTime[i] <= doubleClickTime)
					buttonMap[i] = Button::DoubleClick;

				buttonCount[i] = 0;
			}
		}
	}

	POINT point;
	GetCursorPos(&point);
	ScreenToClient(handle, &point);
	wheelPrevValue = wheelValue;
	wheelMoveValue = wheelValue - wheelPrevValue;


}
