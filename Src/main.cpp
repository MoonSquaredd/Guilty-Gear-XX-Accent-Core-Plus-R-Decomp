//this is NOT finished

#include <steam_api.h>
#include <string.h>
#include <windows.h>

HWND hwnd;
HANDLE handle;
HANDLE MutexHandle;
HBITMAP hBMP;
HDC ghdc;
bool nohotplugging = true;
bool requireaudio = true;
bool socdlikehitbox = false;
bool vjoyfix = true;
bool disablecrashdumps = false;
bool MouseVisible = true;
int WindowMode;
int RectWidth;
int RectHeight;
int bitmapW;
int bitmapH;
int FullScreen;
int WindowResolutionWidth[2];
int WindowResolutionHeight[2];
int AspectRatioFixed;
int RefreshRate;
int V-Sync;

LRESULT WndProc(HWND hwnd, uint uMsg, WPARAM wParam, LPARAM lParam) {
  if (WM_KEYDOWN < uMsg) {
    if (WM_LBUTTONUP < uMsg) {
      if (uMsg == WM_DEVICECHANGE) {
        //something
      } else if ((uMsg == WM_MOUSEHOVER) && MouseVisible != false) {
        ShowCursor(false);
        MouseVisible = false;
      }
      return DefWindowProcW(hwnd,uMsg,wParam,lParam);
    }
    if (uMsg == WM_LBUTTONUP) {
      
    }
  }
  switch (uMsg) {
    case WM_CREATE:
      HDC hdc = GetDc(hwnd);
      ghdc = CreateCompatibleDC(hdc);
      hBMP = CreateCompatibleBitmap(hdc,bitmapW,bitmapH);
      SelectObject(ghdc,hBMP);
      ReleaseDC(hwnd,hdc);
      break;
    case WM_DESTROY:
      ShowWindow(hwnd,SW_HIDE);
      DeleteDC(ghdc);
      DeleteObject(hBMP);
      PostQuitMessage(0);
      break;
  }
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
  if (SteamAPI_RestartAppIfNecessary(348550)) {
    return -1;
  }
  if (!SteamAPI_Init()) {
    MessageBoxA(hwnd, "Steam must be running to play this game (SteamAPI_Init() failed).", "Error", MB_ICONSTOP);
    return -1;
  }
  
  if (0 < (argc - 1)) {
    for (int i = 0, i < (argc-1), i++) {
      if (strcmp(argv[i], "+nohotplugging") == 0) {
        hotplugging = false;
      } else {
        if (strcmp(argv[i], "+connect_lobby") == 0) {
          if (argv[i+1] < (argc-1)) {
            longlong id = std::stoll(argv[i+1]);
            ?? = id >> 0x20;
            ?? = id;
          }
        } else {
          if (strcmp(argv[i], "-norequireaudio") == 0) {
            requireaudio = false;
          } else {
            if (strcmp(argv[i], "/reboot") == 0) {
              long d = std::stol(argv[i+1]);
              // do stuff
            } else {
              if (strcmp(argv[i], "-socdlikehitbox") == 0) {
                socdlikehitbox = true;
              } else {
                if (strcmp(argv[i], "-vjoyfix") == 0) {
                  vjoyfix = false;
                } else {
                  if (strcmp(argv[i], "-disablecrashdumps") == 0) {
                    disablecrashdumps = true;
                  } // there are still more elses
                }
              }
            }
          }
        }
      }
    }
  }

  handle = OpenMutexW(0x1F0001,false,L"GUILTY GEAR XX ΛCORE PLUS R");
  if (handle == NULL) {
    CloseHandle(handle);
    return 0;
  }
  MutexHandle = CreateMutexW(0x0,false,L"GUILTY GEAR XX ΛCORE PLUS R");
  // load settings

  ?? = 32;
  ?? = 32;
  WindowMode = FullScreen;
  RectWidth = WindowResolutionWidth[FullScreen & 1];
  RectHeight = WindowResolutionHeight[FullScreen & 1];
  ?? = (AspectRatioFixed != 0);
  bitmapW = 1280;
  bitmapH = 720;
  ?? = RefreshRate;
  ?? = V-Sync;

  LPRECT rect;
  SetRect(&rect,0,0,RectWidth,RectHeight);
  if (WindowMode == 1) { // Fullscreen
    dwStyle = WS_POPUP;
  } else {
    dwStyle = 0x00ca0000 + (-(WindowMode != 0) & 0x8f360000);
  }
  AdjustWindowRect(rect,dwStyle,false);
  int WindowW = rect.right - rect.left;
  int WindowH = rect.bottom - rect.top;

  WNDCLASSW WNDCLASS = {0};
  WNDCLASS.hbrBackground = GetStockObject(4);
  WNDCLASS.hCursor = LoadCursorW(NULL, IDC_ARROW);
  WNDCLASS.hInstance = hInstance;
  WNDCLASS.lpfnWndProc = WndProc;
  WNDCLASS.lpszClassName = L"GUILTY GEAR XX ΛCORE PLUS R";
  WNDCLASS.hIcon = LoadIconW(hInstance, 107);
  WNDCLASS.style = CS_BYTEALIGNCLIENT | CS_HREDRAW | CS_VREDRAW;

  if ((RegisterClassW(&WNDCLASS)) && (CreateWindowExW(0,L"GUILTY GEAR XX ΛCORE PLUS R",L"GUILTY GEAR XX ΛCORE PLUS R",dwStyle,CW_USEDEFAULT,CW_USEDEFAULT,WindowW,WindowH,NULL,NULL,hInstance,NULL))) {
    if (WindowMode == 1) { // Fullscreen
      ShowCursor(true);
    }
    ShowWindow(hwnd,SW_SHOW);
    UpdateWindow(hwnd);
    if (WindowMode == 0) { // Windowed
      SetWindowLongW(hwnd,GWL_STYLE,WS_VISIBLE | WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU);
      int x = (WindowResolutionHeight[FullScreen & 1] / 2) - (WindowResolutionWidht[FullScreen & 1] / 2);
      int y = (GetSystemMetrics(SM_CYSCREEN) / 2) - (GetSystemMetrics(SM_CXSCREEN) / 2);
      SetWindowPos(hwnd,HWND_NOTOPMOST,x,y,WindowW,WindowH,SWP_DRAWFRAME);
      InvalidateRect(hwnd,NULL,true);
      UpdateWindow(hwnd);
      ShowWindow(hwnd,SW_SHOW);
    } else {
      if (WindowMode == 2) { // Borderless
        //todo
      }
    }
  }
}
