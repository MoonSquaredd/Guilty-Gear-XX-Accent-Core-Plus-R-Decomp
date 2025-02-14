//this is NOT finished kthxbye

#include <steam_api.h>
#include <string.h>
#include <windows.h>

HWND hwnd;
HANDLE handle;
HANDLE MutexHandle;
bool nohotplugging = true;
bool requireaudio = true;
bool socdlikehitbox = false;
bool vjoyfix = true;
bool disablecrashdumps = false;

int main(int argc, char* argv[], HINSTANCE hInstance) {
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
            ?? = id >> 32;
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
}
