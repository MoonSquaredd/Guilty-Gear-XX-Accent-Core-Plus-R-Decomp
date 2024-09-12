void SolAct_AirBanditRevolverLand(CHARACTER WORK *offset) // FUN_00650990
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x86);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  offset->actst = offset->actst | 0x400;
  if ((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 1;
  }
  return;
}

void SolAct_AirBanditRevolver2(CHARACTER WORK *offset) // FUN_006509e0
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x85);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  SetLandBreakActno(offset,0x20086);
  return;
}

void SolAct_AirBanditRevolver1(CHARACTER WORK *offset) // FUN_00650a20
{
  offset->CommandFlag = 0xc05f;
  offset->ply->JumpFlag = offset->ply->JumpFlag & 0xfffd;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x84);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 0x20085;
  }
  return;
}

void SolAct_ITIGEKI_Jump(CHARACTER WORK *offset) // FUN_00650a80 - WIP
{
  undefined *puVar1;
  uint uVar2;
  
  offset->CommandFlag = 0xc05f;
  uVar2 = g_info.BattleControlFlag;
  g_info.BattleControlFlag |= 1;
  if (offset->dirflag == 1)
  {
    g_info.BattleControlFlag = uVar2 | 0x801;
  }
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x7f);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  SetLandBreakActno(offset,0x15);
  if ((&DAT_00ad6500)[offset->padid] == 1)
  {
    (offset->ActHeader).flag = (offset->ActHeader).flag & 0xe7ffffff;
    if (offset->HitParam != (DAMAGEPARAM *)0x0)
    {
      puVar1 = &offset->HitParam->field_0xc;
      *(uint *)puVar1 = *(uint *)puVar1 | 0x200000;
    }
  }
  return;
}

void SolAct_ITIGEKI(CHARACTER WORK *offset) // FUN_00650b00
{
  uint uVar1;
  
  offset->CommandFlag = 0xc05f;
  uVar1 = g_info.BattleControlFlag;
  g_info.BattleControlFlag |= 1;
  if (offset->dirflag == 1)
  {
    g_info.BattleControlFlag = uVar1 | 0x801;
  }
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x7e);
    offset->InstSt = offset->InstSt & 0xffdf;
    offset->ply->OverKillFlag = 2;
  }
  if ((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 0x7f;
  }
  return;
}

void SolAct_OVERKILLMODE(CHARACTER WORK *offset) // FUN_00650b70
{
  offset->CommandFlag = 0xc05f;
  g_info.BattleControlFlag |= 0x10;
  if ((*(byte *)&offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x7b);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_EntryVsFR_2(CHARACTER WORK *offset) // FUN_00650be0
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x113);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_EntryVsFR_1(CHARACTER WORK *offset) // FUN_00650c40
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x112);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryVsIN_2(CHARACTER WORK *offset) // FUN_00650c70
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xfd);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_EntryVsIN_1(CHARACTER WORK *offset) // FUN_00650cd0
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xfc);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryVsSY_2(CHARACTER WORK *offset) // FUN_00650d00
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xfb);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_EntryVsSY_1(CHARACTER WORK *offset) // FUN_00650d60
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xfa);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryVsAXA_2(CHARACTER WORK *offset) // FUN_00650d90
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xf9);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_EntryVsAXA_1(CHARACTER WORK *offset) // FUN_00650df0
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xf8);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryVsKY_2(CHARACTER WORK *offset) // FUN_00650e20
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xc2);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_EntryVsKY_1(CHARACTER WORK *offset) // FUN_00650e80
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xc1);
    offset->InstSt = offset->InstSt & 0xffdf;
    offset->xspeed = (-(uint)(offset->dirflag != '\0') & 18000) - 9000;
    return;
  }
  offset->xspeed = 0;
  return;
}

void SolAct_EntryC_2(CHARACTER WORK *offset) // FUN_00650ee0
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xda);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_EntryC_1(CHARACTER WORK *offset) // FUN_00650f40
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xd9);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryB_2(CHARACTER WORK *offset) // FUN_00650f70
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x7a);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_EntryB_1(CHARACTER WORK *offset) // FUN_00650fd0
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x79);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryA_2(CHARACTER WORK *offset) // FUN_00651000
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x78);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_EntryA_1(CHARACTER WORK *offset) // FUN_00651060
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x77);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_DeadAngle(CHARACTER WORK *offset) // FUN_00651090
{
  offset->actst = offset->actst & 0xfffffbff;
  offset->CommandFlag = 0xc05f;
  if (((short)offset->ActTimer < 5) || (offset->ActTimer == 4))
  {
    offset->SpriteFlag = offset->SpriteFlag | 0x200;
  }
  else
  {
    offset->SpriteFlag = offset->SpriteFlag & 0xfffffdff;
  }
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x63);
    offset->InstSt = offset->InstSt & 0xffdf;
    Tension_Dec(offset,-4);
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_DIGunflame(CHARACTER WORK *offset) // FUN_00651130
{
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xf4);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_GunflameFeint(CHARACTER WORK *offset) // FUN_00651190
{
  offset->actst = offset->actst & 0xfffffbff;
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xba);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_GunFlame(CHARACTER WORK *offset) // FUN_00651200
{
  offset->actst = offset->actst & 0xfffffbff;
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x62);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}

void SolAct_WinC(CHARACTER WORK *offset) // FUN_00651270
{
  offset->actst = offset->actst | 0x80;
  offset->SpriteFlag = offset->SpriteFlag & 0xffffcfff;
  offset->CommandFlag = 0xc05f;
  SetWinActFlag(offset);
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xc4);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0) || (offset->Mark != 0))
  {
    offset->actst = offset->actst | 0x40000;
  }
  return;
}

void SolAct_WinB(CHARACTER WORK *offset) // FUN_006512e0
{
  offset->actst = offset->actst | 0x80;
  offset->SpriteFlag = offset->SpriteFlag & 0xffffcfff;
  offset->CommandFlag = 0xc05f;
  SetWinActFlag(offset);
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xd8);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0) || (offset->Mark != 0))
  {
    offset->actst = offset->actst | 0x40000;
  }
  return;
}

void SolAct_WinA(CHARACTER WORK *offset) // FUN_00651350
{
  offset->actst = offset->actst | 0x80;
  offset->SpriteFlag = offset->SpriteFlag & 0xffffcfff;
  offset->CommandFlag = 0xc05f;
  SetWinActFlag(offset);
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xc3);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0) || (offset->Mark != 0))
  {
    offset->actst = offset->actst | 0x40000;
  }
  return;
}

void SolAct_TyrantRaveB(CHARACTER WORK *offset) // FUN_006513c0
{
  offset->actst = offset->actst & 0xfffffbff;
  offset->CommandFlag = 0xc05f;
  if (offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x60);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (offset->InstSt & 0xc8) != 0)
  {
    if (offset->ply->pactst & 0x8) == 0)
    {
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0;
      }
    }
    else if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x3d;
      return;
    }
  }
  return;
}
