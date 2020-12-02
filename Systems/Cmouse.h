#pragma once
class Cmouse
{
public:
	Cmouse(HWND handle);
	~Cmouse();

	void WndProc(UINT iMessage, WPARAM wParam, LPARAM lParam);

	void Update();

	D3DXVECTOR2 Position() { return D3DXVECTOR2(position.x - 1920 / 2, -position.y + 1080 / 2); }

public:
	bool Down(UINT button)
	{
		return buttonMap[button] == Button::Down;
	}

	bool Up(UINT button)
	{
		return buttonMap[button] == Button::Up;
	}

	bool Press(UINT button)
	{
		return buttonMap[button] == Button::Press;
	}


	bool DoubleClick(UINT button)
	{
		return buttonMap[button] == Button::DoubleClick;
	}

	float Wheel() { return wheelMoveValue; }



private:
	enum class Button
	{
		None, Down, Up, Press, DoubleClick
	};
private:
	HWND handle;

	D3DXVECTOR2 position;//마우스의 위치?

	//왜 8개의 공간을 만드는가?
	//byte==unsigned char

	byte buttonStatus[8];
	byte buttonPrevStatus[8];
	Button buttonMap[8];

	float wheelValue;
	float wheelPrevValue;
	float wheelMoveValue;

	//dword==unsigned long()
	DWORD doubleClickTime;
	DWORD startDoubleClickTime[8];
	int buttonCount[8];


};