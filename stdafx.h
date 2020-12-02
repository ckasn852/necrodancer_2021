#pragma once
#define VERTICLE 16
#define HORIZONTAL 16
#define BEATFRAME 0.1f
#define ANIMATIONFRAME BEATFRAME * 1.5
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define MoveDistance 0.2f
#define SCALE 4.0f
#define GRID 24
#define WALLHEI 42
const float beatPoY = 400;
#define _USE_MATH_DEFINES
#include <windows.h> 
#include <assert.h> 
#include <string>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>
#include <math.h>
using namespace std;


#include <d3d11.h>
#include <d3dx11.h>
#include <d3dX10.h>
#include <d3dx10math.h>
#include <d3dx11effect.h>
#include <d3dcompiler.h>


#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")
#pragma comment(lib, "effects11d.lib")
#pragma comment(lib, "d3dcompiler.lib")

//DirectWrite
#include <d2d1_2.h>
#include <dwrite.h>
#pragma comment(lib, "d2d1.lib")
#pragma comment(lib, "dwrite.lib")


//ImGui
#include <imgui.h>
#include <imguiDx11.h>
#pragma comment(lib, "imgui.lib")


#include "Systems/Keyboard.h"
#include "Systems/Cmouse.h"
#include "Systems/Time.h"
#include "Systems/DirectWrite.h"


#include "Renders/Shader.h"
#include "Renders/Sprite.h"
#include "Renders/Clip.h"
#include "Renders/Animation.h"

#include "Utilities/Math.h"
#include "Utilities/Path.h"
#include "Utilities/String.h"
#include "Utilities/BinaryFile.h"
#include "Utilities/Xml.h"
#include "Utilities/Location.h"
#include "Utilities/Word.h"
#include "Utilities/Sentence.h"

#include "Scenes/Huds/Beat.h"

#define SAFE_RELEASE(p){ if(p){ (p)->Release(); (p) = NULL; } }
#define SAFE_DELETE(p){ if(p){ delete (p); (p) = NULL; } }
#define SAFE_DELETE_ARRAY(p){ if(p){ delete [] (p); (p) = NULL; } }



const wstring CryptTextures = L"../_CryptTextures/";
const wstring Textures = L"../_Textures/";
const wstring Shaders = L"../_Shaders/";
const wstring Shaders9 = Shaders + L"009_Sprite.fx";
const wstring HudTextures = CryptTextures + L"Miscellaneous/HUD.png";

extern UINT Width;
extern UINT Height;

extern HWND Hwnd;
extern wstring Title;

extern IDXGISwapChain* SwapChain;
extern ID3D11Device* Device;
extern ID3D11DeviceContext* DeviceContext;
extern ID3D11RenderTargetView* RTV;

extern Keyboard* Key;
extern Cmouse* Mouse;//변수에 전역성을 부여함
extern Time* Timer;
extern Word* Words;
extern Beat* Beats;
extern D3DXVECTOR2* CameraPosition;