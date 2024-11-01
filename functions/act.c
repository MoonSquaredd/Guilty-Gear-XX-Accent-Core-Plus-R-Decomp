#include <GGXXACPR_WinExe.h> // <= this is still outdated as of Oct 18 2024
#include <stddef.h>

void __fastcall DirectionDirectChange(CHARACTER_WORK *offset); // In actsub.c
void __fastcall SetExCollision(CHARACTER_WORK *offset, short x, short y, ushort w, ushort h, uint attr); // In gcl.c
void __fastcall SetLandBreakActno(CHARACTER_WORK *offset, uint no); // In actsub2.c
void __fastcall SetPriorityMain(CHARACTER_WORK *offset, int PriAdd, int flag); // In actsub.c
void __fastcall ZTED_Time_Dec(CHARACTER_WORK *offset, int val); // In zte_act.c
int __fastcall CmnGuardAct(CHARACTER_WORK *offset, TACTHEADER* header, int cnt); // In p1colchk.c
int __fastcall Random(int seed); // In random.c
int dptoli(double arg_a); // Unk, Converts Double-Precision Floats into Signed Integers

extern GAME_INFORMATION g_info;
extern GROUND_SHAKE groundshakey;
extern CHARACTER_WORK *PlayerWork;
extern int PLAYER_HITPOINTMAX;
extern int RandomSeed;
extern int RandomSeed2;

extern CHARACTER_WORK *PTR_00ad27a8 // Unk global
extern int INT_00ad0538; // Unk global

ACT_FUNC_SIZE Act_Func_Size_Tb[105]; // i'll be filling this later

void __cdecl af_ASTFLAGCONTROL(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  uint flag;
  uchar proc;
  
  proc = ip->arg1;
  flag = 0;
  if (proc == '\0')
  {
    flag = 0x100000;
  }
  else if (proc == '\x01')
  {
    flag = 0x1000000;
  }
  else if (proc == '\x02')
  {
    flag = 0x4000000;
  }
  if (ip->arg2 != 0)
  {
    offset->actst = offset->actst | flag; //Sets the state flag
    return;
  }
  offset->actst = offset->actst & ~flag; //Unsets the state flag
  return;
}

void __cdecl af_BACK_MOTION(CHARACTER_WORK *offset,TACTNORMAL *ip)
{  
  if (ip->arg1 == '\0')
  {
    offset->actst = offset->actst | 0x40;
    (offset->ActHeader).flag = (offset->ActHeader).flag & 0xffffdfff;
    offset->GuardSt = offset->GuardSt & 0xfbff;
    offset->attackst = offset->attackst & 0xffffbfcf | 0xc00;
    if (offset->idno == 0xd)
    {
      offset->ply->PersonalWork[0].w[1] = 0;
    }
    if (((offset->parentFlag & 0x80) != 0) && ((CHARACTER_WORK *)offset->parentWork != (CHARACTER_WORK *)0x0))
    {
      Parent_BACK_MOTION((CHARACTER_WORK *)offset->parentWork);
      return;
    }
  }
  else if (ip->arg1 == '\x01')
  {
    offset->actst = offset->actst | 0x40;
    offset->GuardSt = offset->GuardSt & 0xfbff;
    (offset->ActHeader).flag = (offset->ActHeader).flag & 0xffffdfff;
    offset->attackst = offset->attackst & 0xffffbfff | 0x800;
  }
  return;
}

void __cdecl af_RENEWAL_COLLISION(CHARACTER_WORK *offset)
{
  if (((DAT_00ad0538 == 0) || (((offset->idno != 0x22 && (offset->idno != 0x31)) || ((offset->transSpeed & 0x1000) == 0)))) && (offset->ActHitCount < offset->MaxHitCount))
  {
    offset->actst = offset->actst & 0xffffffbf;
  }
  return;
}

void __cdecl af_SETCOLLISIONDATA(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  if (ip->arg1 == '\x01')
  {
    SetExCollision(offset,-1000,-2,2000,4,1);
  }
  return;
}

void __cdecl af_SEMITRANS(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  if ((ip->arg2 & 0x8000) == 0)
  {
    offset->trans = ip->arg1;
    offset->transmode = *(char *)&ip->arg2;
  }
  offset->trans2 = ip->arg1;
  offset->transmode2 = *(char *)&ip->arg2;
  return;
}

void __cdecl af_SCALE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  double dpVar1;
  int rng;
  uchar proc;
  
  proc = ip->arg1;
  if (proc == '\x01')
  {
    offset->scale = ip->arg2;
    return;
  }
  if (proc == '\0')
  {
    offset->scaleY = ip->arg2;
    return;
  }
  if (proc == '\x03')
  {
    offset->scale = offset->scale + ip->arg2;
    return;
  }
  if (proc == '\x02')
  {
    offset->scaleY = offset->scaleY + ip->arg2;
    return;
  }
  if (proc == '\x05')
  {
    rng = Random(RandomSeed2);
    offset->scale = offset->scale + ((ushort)rng & ip->arg2);
    return;
  }
  if (proc == '\x04')
  {
    rng = Random(RandomSeed2);
    offset->scaleY = offset->scaleY + ((ushort)rng & ip->arg2);
    return;
  }
  if (proc == '\a')
  {
    dpVar1 = (offset->scale * (ip->arg2 / 100.0))
    scale = dptoli(dpVar1);
    offset->scale = (ushort)scale;
    return;
  }
  if (proc == '\x06')
  {
    dpVar1 = (offset->scale * (ip->arg2 / 100.0))
    scale = dptoli(dpVar1);
    offset->scaleY = (ushort)scale;
  }
  return;
}

void __cdecl af_ROT(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  uint u_rng;
  int rng;
  uchar proc;
  
  proc = ip->arg1;
  if (proc == '\0')
  {
    offset->angle = ip->arg2;
    return;
  }
  if (proc == '\x01')
  {
    if (ip->arg2 == 0)
    {
      u_rng = Random(RandomSeed);
      offset->angle = (ushort)((u_rng & 0xff) << 8);
      return;
    }
    rng = Random(RandomSeed);
    offset->angle = (ushort)rng & ip->arg2;
    return;
  }
  if (proc == '\x02')
  {
    offset->angle = offset->angle + ip->arg2;
    return;
  }
  if (proc == '\x03')
  {
    offset->angle = offset->Localid * 256;
    return;
  }
  if (proc == '\x04')
  {
    rng = Random(RandomSeed);
    offset->angle = offset->angle + ((ushort)rng & ip->arg2);
    return;
  }
  if (proc == '\x05')
  {
    u_rng = Random(RandomSeed);
    offset->angle = offset->angle + (short)((ulonglong)u_rng % (ulonglong)ip->arg2);
  }
  return;
}

void __cdecl af_COMMUNICATE(CHARACTER_WORK *offset,TACT3B *ip)
{
  CHARACTER_WORK *new_offset;
  uchar ply;
  
  ply = ip->arg1;
  new_offset = offset;
  if (ply != 0)
  {
    if (ply == 1)
    {
      ply = offset->padid;
    }
    else
    {
      new_offset = (CHARACTER_WORK *)0x0;
      if (ply == 2)
      {
        ply = offset->padid == '\0';
        new_offset = PlayerWork + ply;
      }
    }
  }
  if (ip->arg2 == 0)
  {
    ZTED_Time_Dec(new_offset,(uint)ip->arg3);
  }
  return;
}

void __cdecl af_DO_NOT_CHECK_ATTACK(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  offset->actst = offset->actst | 0x40;
  return;
}

void __cdecl af_DO_NOT_CHECK_DAMAGE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  offset->actst = offset->actst | 0x80;
  return;
}

void __cdecl af_REVERSE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  if (ip->arg1 == '\x01')
  {
    DirectionDirectChange(offset);
    return;
  }
  offset->dirflag = offset->dirflag == 0;
  return;
}

void __cdecl af_DRAW_NORMAL(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  offset->dirflag = 0;
  return;
}

void __cdecl af_DRAW_REVERSE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  offset->dirflag = 1;
  return;
}

void __cdecl af_PARENT_OFFSET_POS_X(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  ushort pos;
  CHARACTER_WORK *parentWrk;
  
  pos = ip->arg2;
  parentWrk = offset->parentWork;
  offset->parentx = uVar1;
  if (parentWrk->dirflag == 1)
  {
    offset->posx = parentWrk->posx + (short)pos * -100;
    return;
  }
  offset->posx = parentWrk->posx + (short)pos * 100;
  return;
}

void __cdecl af_PARENT_OFFSET_POS_Y(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  ushort pos;
  
  pos = ip->arg2;
  offset->parenty = pos;
  offset->posy = offset->parentWork->posy + (short)pos * 100;
  return;
}

void __cdecl af_ENEMY_HIT_SE_MODE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  DAMAGEPARAM *dParams;
  int iVar2;
  
  dParams = offset->HitParam;
  iVar2 = 0;
  if (dParams != (DAMAGEPARAM *)0x0)
  {
    if ((dParams->HitSE).param.flag[0] != '\0')
    {
      iVar2 = 1;
    }
    dParams->HitSE.param.no[iVar2]) = ip->arg1;
    dParams->HitSE.param.flag[iVar2]) = *(uchar *)ip->arg2;
  }
  return;
}

void __cdecl af_ENEMY_GUARD_SE_MODE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  DAMAGEPARAM *dParams;
  int iVar2;
  
  dParams = offset->HitParam;
  iVar2 = 0;
  if (dParams != (DAMAGEPARAM *)0x0)
  {
    if ((dParams->GuardSE).param.flag[0] != '\0')
    {
      iVar2 = 1;
    }
    dParams->HitSE.param.no[iVar2]) = ip->arg1;
    dParams->HitSE.param.flag[iVar2]) = *(uchar *)ip->arg2;
  }
  return;
}

void __cdecl af_GUARD_VOICE(CHARACTER_WORK *offset,TACT3B *ip)
{
  if (offset->HitParam != (DAMAGEPARAM *)0x0)
  {
    offset->HitParam->gno = ip->arg1;
    offset->HitParam->gprob = ip->arg3;
  }
  return;
}

void __cdecl af_DAMAGE_VOICE(CHARACTER_WORK *offset,TACT3B *ip)
{
  if (offset->HitParam != (DAMAGEPARAM *)0x0)
  {
    offset->HitParam->dno = ip->arg1;
    offset->HitParam->dprob = ip->arg3;
  }
  return;
}

void __cdecl af_DOWN_GRAV(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  DAMAGEPARAM *pDVar1;
  
  pDVar1 = offset->HitParam;
  if (pDVar1 != (DAMAGEPARAM *)0x0)
  {
    if (ip->arg1 == '\0')
    {
      pDVar1->DownGrav = ip->arg2;
      return;
    }
    pDVar1[1].DownGrav = ip->arg2;
  }
  return;
}

void __cdecl af_DOWN_X(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  DAMAGEPARAM *pDVar1;
  
  pDVar1 = offset->HitParam;
  if (pDVar1 != (DAMAGEPARAM *)0x0)
  {
    if (ip->arg1 == '\0')
    {
      pDVar1->DownX = ip->arg2;
      return;
    }
    pDVar1[1].DownX = ip->arg2;
  }
  return;
}

void __cdecl af_DOWN_Y(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  DAMAGEPARAM *pDVar1;
  
  pDVar1 = offset->HitParam;
  if (pDVar1 != (DAMAGEPARAM *)0x0)
  {
    if (ip->arg1 == '\0')
    {
      pDVar1->DownY = ip->arg2;
      return;
    }
    pDVar1[1].DownY = ip->arg2;
  }
  return;
}

void __cdecl af_DELETE_ITTAI(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  DeleteIttai(offset);
  return;
}

void __cdecl af_FADE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  uchar uVar1;
  ushort uVar2;
  CHARACTER_WORK *pCVar3;
  uchar bVar4;
  uchar bVar5;
  
  uVar1 = ip->arg1;
  if (uVar1 == '\x03')
  {
    if (ip->arg2 != 0)
    {
      bVar4 = offset->padid == '\0';
      offset->SpriteFlag = offset->SpriteFlag | 0x40000;
      PlayerWork[bVar4].SpriteFlag = PlayerWork[bVar4].SpriteFlag | 0x40000;
      offset->FadeVal = '\0';
      PlayerWork[bVar4].FadeVal = '\0';
      return;
    }
    offset->SpriteFlag = offset->SpriteFlag & 0xfffbffff;
    PlayerWork[offset->padid == '\0'].SpriteFlag = PlayerWork[offset->padid == '\0'].SpriteFlag & 0xfffbffff;
    return;
  }
  if (uVar1 == '\x04')
  {
    uVar2 = ip->arg2;
  }
  else
  {
    if (uVar1 == '\x05')
    {
      bVar5 = offset->padid;
    }
    else
    {
      if (uVar1 != '\x06')
      {
        if (uVar1 == '\a')
        {
          if (ip->arg2 != 0)
          {
            g_info.BattleControlFlag |= 2;
            return;
          }
          if ((g_info.BattleControlFlag & 0x10000) == 0)
          {
            g_info.BattleControlFlag &= 0xfffffffd;
            return;
          }
        }
        else
        {
          if (uVar1 == '\x02')
          {
            if (ip->arg2 != 0)
            {
              g_info.BattleControlFlag |= 8;
              return;
            }
            g_info.BattleControlFlag &= 0xfffffff7;
            return;
          }
          if (uVar1 == '\x01')
          {
            FadeEndCommand = 0;
            FadeSpeed = (float)(uint)ip->arg2;
            Rq_Fadeout();
            FadeCockpitFlag = 1;
            return;
          }
          FadeEndCommand = 0;
          FadeSpeed = (float)(uint)ip->arg2;
          Rq_Fadein();
          FadeCockpitFlag = 1;
        }
        return;
      }
      bVar5 = offset->padid == '\0';
    }
    offset = PlayerWork + bVar5;
    uVar2 = ip->arg2;
  }
  if (0xfe < uVar2)
  {
    offset->SpriteFlag = offset->SpriteFlag & 0xfffbffff;
    offset->FadeVal = *(char *)&ip->arg2;
    return;
  }
  offset->SpriteFlag = offset->SpriteFlag | 0x40000;
  offset->FadeVal = *(char *)&ip->arg2;
  return;
}

void __cdecl af_SET_PRIORITY(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  uint flag;
  uint flag2;
  
  flag = ~ip->arg1 & 1;
  flag2 = flag | 2;
  if ((ip->arg1 & 2) == 0)
  {
    if (true)
    {
      switch(ip->arg2)
      {
      case 0:
        SetPriorityMain(offset,0,flag2);
        return;
      case 0xf7:
        SetPriorityMain(offset,-2,flag | 6);
        return;
      case 0xf8:
        SetPriorityMain(offset,2,flag | 6);
        return;
      case 0xf9:
        SetPriorityMain(offset,65,flag2);
        return;
      case 0xfa:
        SetPriorityMain(offset,55,flag2);
        return;
      case 0xfb:
        SetPriorityMain(offset,-30,flag2);
        return;
      case 0xfc:
        SetPriorityMain(offset,-10,flag2);
        return;
      case 0xfd:
        SetPriorityMain(offset,10,flag2);
        return;
      case 0xfe:
        SetPriorityMain(offset,-15,flag2);
        return;
      }
    }
    offset->SpriteFlag = offset->SpriteFlag | 2;
    SetPriorityMain(offset,(uint)ip->arg2,flag2);
    return;
  }
  SetPriorityMain(offset,(int)(short)ip->arg2,flag2);
  return;
}

void __cdecl af_SET_DAMAGE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  SetDamage(offset,ip->arg2);
  return;
}

void __cdecl af_SET_LEVEL(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  (offset->ActHeader).lvflag = ip->arg2;
  return;
}

void __cdecl af_SET_ACTTYPE(CHARACTER_WORK *offset,TSET_ACTTYPE *ip)
{
  if (ip->arg1 == '\x01')
  {
    (offset->ActHeader).flag = (offset->ActHeader).flag & 0xffffe3ff;
    (offset->ActHeader).flag = ip->type & 0x1c00 | (offset->ActHeader).flag;
    return;
  }
  (offset->ActHeader).flag = ip->type;
  return;
}

void __cdecl af_SET_DOWNTIME(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  DAMAGEPARAM *pDVar1;
  
  pDVar1 = offset->HitParam;
  if (pDVar1 != (DAMAGEPARAM *)0x0)
  {
    if (ip->arg1 == '\0')
    {
      pDVar1->DownUkemiTime = ip->arg2;
      return;
    }
    pDVar1[1].DownUkemiTime = ip->arg2;
  }
  return;
}

void __cdecl af_POSBYENEMY(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  if (offset->ply != (PLAYER_ENTRY *)0x0)
  {
    offset->ply->PosByEnemyAddr = ip;
  }
  return;
}

void __cdecl af_SETMARK(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  if ((ip->arg1 & 2) != 0)
  {
    offset = PlayerWork + offset->padid;
  }
  if ((ip->arg1 & 1) != 0)
  {
    offset->Mark = *(uchar *)&ip->arg2;
    return;
  }
  offset->Mark = offset->Mark | *(uchar *)&ip->arg2;
  return;
}

void __cdecl af_SETMASK(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  if ((ip->arg1 & 2) != 0)
  {
    offset = PlayerWork + offset->padid;
  }
  offset->Mark = offset->Mark & ~*(uchar *)&ip->arg2;
  return;
}

void __cdecl af_SETMAXHIT(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  offset->MaxHitCount = ip->arg1;
  return;
}

void __cdecl af_INDEPENDENCE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  uchar proc;
  
  proc = ip->arg1;
  if (proc == '\x03')
  {
    offset->parentFlag = offset->parentFlag | 0x4000;
    return;
  }
  if (proc == '\x02')
  {
    offset->parentFlag = offset->parentFlag & 0x1a03;
    return;
  }
  if (proc == '\x01')
  {
    offset->parentFlag = offset->parentFlag | 0x80;
    return;
  }
  offset->parentFlag = offset->parentFlag & 0x1a00;
  return;
}

void __cdecl af_VEBALL(CHARACTER_WORK *offset,TACT3B *ip)
{
  offset->attackst = offset->attackst | 0x4000;
  if (offset->ply != (PLAYER_ENTRY *)0x0)
  {
    offset->ply->PersonalWork[0].b[2] = ip->arg1;
    offset->ply->PersonalWork[0].b[0] = ip->arg2;
    offset->ply->PersonalWork[0].b[3] = ip->arg3;
  }
  return;
}

void __cdecl af_PALETTE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  if (ip->arg1 == '\0')
  {
    offset->PaletteFlag = offset->PaletteFlag | 1;
    offset->LocalPalette = *(char *)&ip->arg2;
    return;
  }
  if (ip->arg1 == '\x01')
  {
    offset->PaletteFlag = offset->PaletteFlag | 2;
    offset->LocalPalette = *(char *)&ip->arg2;
  }
  return;
}

void __cdecl af_REVIVEDAMAGE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  offset->actst = offset->actst & 0xffffff7f;
  return;
}

void __cdecl af_FREEIMAGE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  offset->SpriteFlag = offset->SpriteFlag | 0x100;
  return;
}

void __cdecl af_SETGRAVITY(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  offset->gravity = (int)(short)ip->arg2;
  return;
}

void __cdecl af_RENDACHANSEL(CHARACTER_WORK *offset,TACTNORMALQUAD *ip)
{
  uint *rflag;
  
  rflag = &offset->ply->rendaflag;
  *rflag = *rflag | ip->arg3;
  if (ip->arg1 == 1)
  {
    offset->ply->rendaflag = 0;
  }
  return;
}

void __cdecl af_GROUNDSHAKE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  groundshakey.move = 0.0;
  groundshakey.power = ip->arg2;
  groundshakey.time = 1;
  return;
}

void __cdecl af_KEZURI(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  if (offset->HitParam != (DAMAGEPARAM *)0x0)
  {
    offset->HitParam->Kezuri = ip->arg2;
  }
  return;
}

void __cdecl af_FAINT(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  if (offset->HitParam != (DAMAGEPARAM *)0x0)
  {
    offset->HitParam->FaintPoint = ip->arg2;
  }
  return;
}

void __cdecl af_SIT(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  if (ip->arg2 != 0)
  {
    offset->actst = offset->actst | 0x400;
    return;
  }
  offset->actst = offset->actst & 0xfffffbff;
  return;
}

void __cdecl af_JUMPCONTROL(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  ushort *puVar1;
  ushort proc;
  
  proc = ip->arg2;
  if (proc == 1)
  {
    SetLandBreakActno(offset,0x15);
    return;
  }
  if (proc == 2)
  {
    if (ip->arg1 != '\0')
    {
      puVar1 = &offset->ply->JumpFlag;
      *puVar1 = *puVar1 | 2;
      return;
    }
    puVar1 = &offset->ply->JumpFlag;
    *puVar1 = *puVar1 & 0xfffd;
    return;
  }
  if (proc != 3)
  {
    SetLandBreakActno(offset,0xffffffff);
    return;
  }
  if (ip->arg1 != '\0')
  {
    puVar1 = &offset->ply->JumpFlag;
    *puVar1 = *puVar1 | 0x80;
    return;
  }
  puVar1 = &offset->ply->JumpFlag;
  *puVar1 = *puVar1 & 0xff7f;
  return;
}

void __cdecl af_MUTEKI(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  offset->ply->MutekiTime = *(char *)&ip->arg2;
  offset->actst = offset->actst | 0x20000;
  return;
}

void __cdecl af_NOTHROW(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  if (ip->arg2 != 0)
  {
    offset->actst = offset->actst | 0x800000;
    return;
  }
  offset->actst = offset->actst & 0xff7fffff;
  return;
}

void __cdecl af_AFTERIMAGE(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  short *psVar1;
  ushort uVar2;
  
  if (offset->ply != (PLAYER_ENTRY *)0x0)
  {
    uVar2 = ip->arg2;
    if (uVar2 == 0)
    {
      if (ip->arg1 != '\0')
      {
        psVar1 = &offset->ply->pactst;
        *psVar1 = *psVar1 | 2;
        return;
      }
      psVar1 = &offset->ply->pactst;
      *psVar1 = *psVar1 & 0xfffd;
      return;
    }
    if (uVar2 == 1)
    {
      if (ip->arg1 != '\0')
      {
        psVar1 = &offset->ply->pactst;
        *psVar1 = *psVar1 | 0x2000;
        return;
      }
      psVar1 = &offset->ply->pactst;
      *psVar1 = *psVar1 & 0xdfff;
      return;
    }
    if (uVar2 == 2)
    {
      if (ip->arg1 != '\0')
      {
        psVar1 = &offset->ply->pactst;
        *psVar1 = *psVar1 | 0x4000;
        return;
      }
      psVar1 = &offset->ply->pactst;
      *psVar1 = *psVar1 & 0xbfff;
      return;
    }
    if (uVar2 == 3)
    {
      if (ip->arg1 != '\0')
      {
        psVar1 = &offset->ply->pactst;
        *psVar1 = *psVar1 | 8;
        return;
      }
      psVar1 = &offset->ply->pactst;
      *psVar1 = *psVar1 & 0xfff7;
      return;
    }
    if (uVar2 == 4)
    {
      if (ip->arg1 != '\0')
      {
        psVar1 = &offset->ply->pactst;
        *psVar1 = *psVar1 | 0x80;
        return;
      }
      psVar1 = &offset->ply->pactst;
      *psVar1 = *psVar1 & 0xff7f;
    }
  }
  return;
}

void __cdecl af_GUARD(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  short sVar1;
  
  if (ip->arg1 == '\0')
  {
    if (offset->ply != (PLAYER_ENTRY *)0x0)
    {
      offset->ply->ExCommandFunc = &LAB_006ac570; // Imediatelly returns 0
    }
    if (offset->ply != (PLAYER_ENTRY *)0x0)
    {
      offset->ply->GuardFunc = &LAB_006ac580; // Imediatelly returns 0
    }
    offset->attackst = offset->attackst & 0xffefffff;
    offset->GuardSt = 0;
  }
  else
  {
    offset->ply->GuardFunc = CmnGuardAct;
    sVar1 = 0x201;
    if (ip->arg2 == 0)
    {
      sVar1 = 0x202;
    }
    offset->GuardSt = sVar1;
    offset->attackst = offset->attackst & 0xfffffdff | 0x300000;
    if ((ip->arg1 == '\x02') && (INT_00ad0538 != 0))
    {
      offset->GuardSt = offset->GuardSt | 0x8000;
      return;
    }
  }
  return;
}

void __cdecl af_UseParentHeader(CHARACTER_WORK *offset,TACTNORMAL *ip)
{
  uchar uVar1;
  uchar uVar2;
  CHARACTER_WORK *pvVar2;
  
  pvVar2 = offset->parentWork;
  if (pvVar2 != (CHARACTER_WORK *)0x0)
  {
    (offset->ActHeader).flag = (pvVar2->ActHeader).flag;
    (offset->ActHeader).lvflag = (pvVar2->ActHeader).lvflag;
    (offset->ActHeader).damage = (pvVar2->ActHeader).damage;
    (offset->ActHeader).flag2 = (pvVar2->ActHeader).flag2;
    offset->HitParam = pvVar2->HitParam;
  }
  return;
}

void __fastcall DeleteIttai(CHARACTER_WORK *offset)
{
  CHARACTER_WORK **ppCVar1;
  CHARACTER_WORK *pCVar2;
  
  pCVar2 = ObjectWork;
  if (ObjectWork != (CHARACTER_WORK *)&PTR_00ad27a8)
  {
    do
    {
      if ((pCVar2->parentFlag != 0) && (offset == pCVar2->parentWork))
      {
        pCVar2->actst = pCVar2->actst | 0xa0000000;
      }
      ppCVar1 = &pCVar2->next;
      pCVar2 = *ppCVar1;
    } while (*ppCVar1 != (CHARACTER_WORK *)&PTR_00ad27a8);
  }
  return;
}

void __cdecl SetDamage(CHARACTER_WORK *offset,ushort damage)
{
  uint finalDmg;
  int hp;
  PLAYER_ENTRY *plyEntry;
  
  if (((offset->ActHeader).flag & 0x8000) != 0)
  {
    hp = (int)(short)PlayerWork[offset->padid == 0].HitPoint;
    if (hp < (int)(PLAYER_HITPOINTMAX + (PLAYER_HITPOINTMAX >> 0x1f & 7U)) >> 3)
    {
      damage = 0;
    }
    if (hp < (int)(PLAYER_HITPOINTMAX + (PLAYER_HITPOINTMAX >> 0x1f & 3U)) >> 2)
    {
      damage >>= 2;
    }
    else if (hp < PLAYER_HITPOINTMAX / 2)
    {
      damage >>= 1;
    }
  }
  plyEntry = PlayerWork[offset->padid].ply;
  if (plyEntry != (PLAYER_ENTRY *)0x0)
  {
    if ((plyEntry->AttackDown == '\0') || (damage == 0))
    {
      if ((offset->idno == 0x16) && (plyEntry->PersonalWork[0].w[0] == 2))
      {
        finalDmg = (((-(uint)(INT_00ad0538 != 0) & 0x14) + 0x50) * (uint)damage) / 100;
        if (finalDmg == 0)
        {
          (offset->ActHeader).damage = '\x01';
          return;
        }
      }
      else
      {
        finalDmg = (uint)(byte)damage;
      }
    }
    else
    {
      finalDmg = (uint)(damage >> 1);
      if (finalDmg == 0)
      {
        (offset->ActHeader).damage = '\x01';
        return;
      }
    }
    (offset->ActHeader).damage = (uchar)finalDmg;
  }
  return;
}

void __fastcall Parent_BACK_MOTION(CHARACTER_WORK *offset)
{
  offset->actst = offset->actst | 0x40;
  (offset->ActHeader).flag = (offset->ActHeader).flag & 0xffffdfff;
  offset->GuardSt = offset->GuardSt & 0xfbff;
  offset->attackst = offset->attackst & 0xffffbfcf | 0xc00;
  if (offset->idno == 0xd)
  {
    offset->ply->PersonalWork[0].w[1] = 0;
  }
  return;
}

void __fastcall NextInstExecute(CHARACTER_WORK *offset)
{
  CHARACTER_WORK *offset2;
  TACTNORMAL *ip;
  TACTNORMAL *CurrentInst;
  TACTNORMAL *CellBegin;
  int instSize;
  TACTNORMAL *inst;

  ip = offset->InstAddr;
  if (ip->id != 0xFF)
  {
    do
    {
      CurrentInst = ip;
      CellBegin = GetCellBeginAddr(offset, ip);
      ip = CellBegin;
    } while (CurrentInst != CellBegin);
    
    if ((ip->id != 0) && (ip->id != 0x61))
    {
      do
      {
        // it is that stupid
      } while (true);
    }
    SetAnimeData(offset, ip);
    instSize = GetInstSize(ip->id);
    inst = ip + (instSize >> 2);
    instId = inst->id;
    while (instId != 0)
    {
      if (instId != 0xFF)
      {
        if (instId != 0x61)
        {
          if (Act_Func_Size_Tb[instId].func != NULL)
          {
            Act_Func_Size_Tb[instId].func(offset, inst);
            instSize = Act_Func_Size_Tb[instId].size;
            if (instId == 0xFF)
            {
              instSize = 4;
            }
            inst = inst + (instSize >> 2);
          }
          else
          {
            if (instId != 0x19)
            {
              if (instId != 0x27)
              {
                if (instId == 0x60)
                {
                  ?? = GetCellBeginAddr(offset, inst); // figuring out
                }
              }
              else
              {
                ?? = GetCellBeginAddr(offset, inst); // figuring out
              }
            }
            else
            {
              // figuring out
            }
          }
        }
      }
      instId = inst->id;
    }
    if (inst->id == 0xFF)
    {
      offset->InstSt |= 1;
      if (inst->arg1 == 3)
      {
        offset->InstSt |= 0x10;
        return;
      }
      if (inst->arg1 == 4)
      {
        offset->InstSt |= 0x200;
        offset->InstVal = inst->arg2;
        return;
      }
      if (inst->arg1 == 5)
      {
        offset->InstSt |= 0x2000;
        return;
      }
      if (inst->arg1 == 6)
      {
        offset->InstSt |= 0x400;
        return;
      }
      if (inst->arg1 == 8)
      {
        offset->InstSt |= 0x800;
        return;
      }
      if (inst->arg1 == 7)
      {
        offset->InstSt |= 0x1000;
        return;
      }
    }
  }
  return;
}
