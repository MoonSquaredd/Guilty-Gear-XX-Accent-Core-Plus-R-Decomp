#include "GGXXACPR_WinExe.h"

extern GAME_INFO g_info;

CHARACTER_WORK PlayerWork[2];

uint data_006D0538; // unknown global

void PlayerExecute(void)
{
  CHARACTER_WORK *plyWrk;
  uint side;

  plyWrk = &PlayerWork;
  if (data_006D0538 != 0)
  {
    plyWrk[0]->ply->DownFlag &= 0xfffdffff;
    plyWrk[1]->ply->DownFlag &= 0xfffdffff;
  }
  if (plyWrk[0]->DamColliFlag == 0)
  {
    if (plyWrk[1]->DamColliFlag == 0)
    {
      if (plyWrk[0]->actst & 0x20 == 0)
      {
        if (plyWrk[1]->actst & 0x20 == 0)
        {
          side = 1;
        }
        else
        {
          side = 0;
        }
      }
      else if (plyWrk[1]->actst & 0x20 == 0)
      {
        side = 1;
      }
      else if (plyWrk[0]->actst & 0x20 == 0)
      {
        side = 0;
      }
      else
      {
        side = TotalCounter & 1;
      }
    }
    else
    {
      side = 1;
    }
  }
  else
  {
    side = 0;
  }
  if (g_info.mode & 0x100 == 0)
  {
    //figuring out
  }
}
