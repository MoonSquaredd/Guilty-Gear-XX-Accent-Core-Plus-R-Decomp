void SolAct_AirBanditRevolverLand(CHARACTER_WORK *offset) // FUN_00650990
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x86);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  offset->actst = offset->actst | 0x400;
  if (((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 1;
  }
  return;
}

void SolAct_AirBanditRevolver2(CHARACTER_WORK *offset) // FUN_006509e0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x85);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  SetLandBreakActno(offset,0x20086);
  return;
}

void SolAct_AirBanditRevolver1(CHARACTER_WORK *offset) // FUN_00650a20
{
  offset->CommandFlag = 0xc05f;
  offset->ply->JumpFlag = offset->ply->JumpFlag & 0xfffd;
  if ((offset->InstSt & 0x20) != 0)
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

void SolAct_ITIGEKI_Jump(CHARACTER_WORK *offset) // FUN_00650a80 - WIP
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
  if ((offset->InstSt & 0x20) != 0)
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

void SolAct_ITIGEKI(CHARACTER_WORK *offset) // FUN_00650b00
{
  uint uVar1;
  
  offset->CommandFlag = 0xc05f;
  uVar1 = g_info.BattleControlFlag;
  g_info.BattleControlFlag |= 1;
  if (offset->dirflag == 1)
  {
    g_info.BattleControlFlag = uVar1 | 0x801;
  }
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x7e);
    offset->InstSt = offset->InstSt & 0xffdf;
    offset->ply->OverKillFlag = 2;
  }
  if (((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 0x7f;
  }
  return;
}

void SolAct_OVERKILLMODE(CHARACTER_WORK *offset) // FUN_00650b70
{
  offset->CommandFlag = 0xc05f;
  g_info.BattleControlFlag |= 0x10;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x7b);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_EntryVsFR_2(CHARACTER_WORK *offset) // FUN_00650be0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x113);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_EntryVsFR_1(CHARACTER_WORK *offset) // FUN_00650c40
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x112);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryVsIN_2(CHARACTER_WORK *offset) // FUN_00650c70
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xfd);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_EntryVsIN_1(CHARACTER_WORK *offset) // FUN_00650cd0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xfc);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryVsSY_2(CHARACTER_WORK *offset) // FUN_00650d00
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xfb);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_EntryVsSY_1(CHARACTER_WORK *offset) // FUN_00650d60
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xfa);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryVsAXA_2(CHARACTER_WORK *offset) // FUN_00650d90
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xf9);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_EntryVsAXA_1(CHARACTER_WORK *offset) // FUN_00650df0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xf8);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryVsKY_2(CHARACTER_WORK *offset) // FUN_00650e20
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xc2);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_EntryVsKY_1(CHARACTER_WORK *offset) // FUN_00650e80
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xc1);
    offset->InstSt = offset->InstSt & 0xffdf;
    offset->xspeed = (-(uint)(offset->dirflag != '\0') & 18000) - 9000;
    return;
  }
  offset->xspeed = 0;
  return;
}

void SolAct_EntryC_2(CHARACTER_WORK *offset) // FUN_00650ee0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xda);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_EntryC_1(CHARACTER_WORK *offset) // FUN_00650f40
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xd9);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryB_2(CHARACTER_WORK *offset) // FUN_00650f70
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x7a);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_EntryB_1(CHARACTER_WORK *offset) // FUN_00650fd0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x79);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_EntryA_2(CHARACTER_WORK *offset) // FUN_00651000
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x78);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_EntryA_1(CHARACTER_WORK *offset) // FUN_00651060
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x77);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  return;
}

void SolAct_DeadAngle(CHARACTER_WORK *offset) // FUN_00651090
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
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x63);
    offset->InstSt = offset->InstSt & 0xffdf;
    Tension_Dec(offset,-4);
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_DIGunflame(CHARACTER_WORK *offset) // FUN_00651130
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xf4);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_GunflameFeint(CHARACTER_WORK *offset) // FUN_00651190
{
  offset->actst = offset->actst & 0xfffffbff;
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xba);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_GunFlame(CHARACTER_WORK *offset) // FUN_00651200
{
  offset->actst = offset->actst & 0xfffffbff;
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x62);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_WinC(CHARACTER_WORK *offset) // FUN_00651270
{
  offset->actst = offset->actst | 0x80;
  offset->SpriteFlag = offset->SpriteFlag & 0xffffcfff;
  offset->CommandFlag = 0xc05f;
  SetWinActFlag(offset);
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xc4);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (((offset->InstSt & 0xc8) != 0) || (offset->Mark != 0))
  {
    offset->actst = offset->actst | 0x40000;
  }
  return;
}

void SolAct_WinB(CHARACTER_WORK *offset) // FUN_006512e0
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
  if (((offset->InstSt & 0xc8) != 0) || (offset->Mark != 0))
  {
    offset->actst = offset->actst | 0x40000;
  }
  return;
}

void SolAct_WinA(CHARACTER_WORK *offset) // FUN_00651350
{
  offset->actst = offset->actst | 0x80;
  offset->SpriteFlag = offset->SpriteFlag & 0xffffcfff;
  offset->CommandFlag = 0xc05f;
  SetWinActFlag(offset);
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xc3);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (((offset->InstSt & 0xc8) != 0) || (offset->Mark != 0))
  {
    offset->actst = offset->actst | 0x40000;
  }
  return;
}

void SolAct_TyrantRaveB(CHARACTER_WORK *offset) // FUN_006513c0
{
  offset->actst = offset->actst & 0xfffffbff;
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x60);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

// DIEnd - FUN_00651430
// DI - FUN_00651570

void SolAct_ForwardRespectA(CHARACTER_WORK *offset) // FUN_00651630
{
  offset->actst = offset->actst & 0xffffefff;
  if (((short)offset->ActTimer < 0x10) || (offset->ActTimer == 0xf))
  {
    offset->CommandFlag = 0xc05f;
  }
  else
  {
    offset->CommandFlag = 0xc01f;
  }
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xd2);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

// RespectB - FUN_006516b0
// RespectA - FUN_00651760

void SolAct_RiotStampLand(CHARACTER_WORK *offset) // FUN_00651810
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x83);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_RiotStampDrop(CHARACTER_WORK *offset) // FUN_00651870
{
  SetLandBreakActno(offset,0xffffffff);
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x82);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (((offset->actst & 0x10) == 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 0x83;
  }
  return;
}

void SolAct_RiotStampAttack(CHARACTER_WORK *offset) // FUN_006518c0
{
  int iVar1;
  
  iVar1 = (int)((ulonglong)((longlong)offset->posy * -0x66666667) >> 0x20);
  offset->CommandFlag = 0xc05f;
  if (offset->posy < -1999)
  {
    offset->yspeed = (iVar1 >> 3) - (iVar1 >> 0x1f);
  }
  else
  {
    offset->yspeed = (iVar1 >> 4) - (iVar1 >> 0x1f);
  }
  if (offset->yspeed < 0x32)
  {
    offset->yspeed = 0x32;
  }
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xd5);
    offset->InstSt = offset->InstSt & 0xffdf;
    offset->yspeed = 0;
    offset->gravity = 0;
    offset->ply->EnemyTouch = 0;
  }
  SetLandBreakActno(offset,0x15);
  if (((offset->attackst & 0x1000) != 0) || ((((offset->actst & 0x2800) != 0 && (5 < (short)offset->ActTimer)) || (10 < offset->ply->EnemyTouch))))
  {
    offset->xspeed = (-(uint)(offset->dirflag != 0) & 600) - 300;
    offset->gravity = (int)Jump_GravityByIdno[offset->padid];
    if (offset->actnonext == 0xffffffff)
    {
      offset->actnonext = 0x20082;
    }
  }
  return;
}

void SolAct_RiotStampWall(CHARACTER_WORK *offset) // FUN_006519c0
{
  offset->actst = offset->actst & 0xfffffbff;
  offset->CommandFlag = 0xc05f;
  scr_stp->stScreenFlag |= 0x40;
  offset->xspeed = 0;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xd4);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (((offset->InstSt & 200) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 0xd4;
  }
  return;
}

void SolAct_RiotStampJump(CHARACTER_WORK *offset) // FUN_00651a20
{
  ushort *puVar1;
  
  offset->actst = offset->actst & 0xfffffbff;
  offset->CommandFlag = 0xc05f;
  puVar1 = &offset->ply->JumpFlag;
  *puVar1 = *puVar1 & 0xfffd;
  scr_stp->stScreenFlag |= 0x40;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xde);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  SetLandBreakActno(offset,0x15);
  if ((((offset->actst & 0x2800) != 0) && (offset->posy < -4000)) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 0x300d3;
  }
  return;
}

void SolAct_AirThrow(CHARACTER_WORK *offset) // FUN_00651aa0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xcc);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  SetLandBreakActno(offset,0x15);
  return;
}

void SolAct_WildThrow_Miss(CHARACTER_WORK *offset) // FUN_00651ae0 - WIP
{
  offset->CommandFlag = 0xc05f;
  *(code **)&offset->ply->field_0x80 = FUN_005208a0;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x88);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_WildThrow(CHARACTER_WORK *offset) // FUN_00651b50
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x87);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_Throw(CHARACTER_WORK *offset) // FUN_00651bb0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xd6);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if ((offset->InstSt & 0xc8) != 0)
  {
    if ((offset->ply->pactst & 0x8) == 0)
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

void SolAct_BanditBringerLand(CHARACTER_WORK *offset) // FUN_00651c10
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xbc);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 1;
  }
  return;
}

void SolAct_toBringer(CHARACTER_WORK *offset) // FUN_00651c60
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xbb);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  SetLandBreakActno(offset,0x200bc);
  return;
}

void SolAct_DIBanditRevolverLand(CHARACTER_WORK *offset) // FUN_00651ca0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x103);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 1;
  }
  return;
}

void SolAct_DItoRevolver(CHARACTER_WORK *offset) // FUN_00651cf0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x102);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  SetLandBreakActno(offset,0x20103);
  return;
}

void SolAct_DIBandit(CHARACTER_WORK *offset) // FUN_00651d30
{
  ushort *puVar1;
  uint uVar2;
  
  offset->CommandFlag = 0xc05f;
  puVar1 = &offset->ply->JumpFlag;
  *puVar1 = *puVar1 & 0xfffd;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x101);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  uVar2 = IsHoldKick(offset);
  if (uVar2 == 0)
  {
    offset->Mark = 1;
  }
  if (((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 0x102;
  }
  return;
}

void SolAct_BanditRevolverLand(CHARACTER_WORK *offset) // FUN_00651da0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xdd);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 1;
  }
  return;
}

void SolAct_toRevolver(CHARACTER_WORK *offset) // FUN_00651df0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xdc);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  SetLandBreakActno(offset,0x200dd);
  return;
}

void SolAct_Bandit(CHARACTER_WORK *offset) // FUN_00651e30 - WIP
{
  ushort *puVar1;
  uint uVar2;
  uint extraout_EDX;
  
  offset->CommandFlag = 0xc05f;
  puVar1 = &offset->ply->JumpFlag;
  *puVar1 = *puVar1 & 0xfffd;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xdb);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  uVar2 = IsHoldKick(offset);
  if ((uVar2 | extraout_EDX) == 0)
  {
    offset->Mark = 1;
  }
  if (offset->Mark == 0)
  {
    if (((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
    {
      offset->actnonext = 0xbb;
    }
  }
  else if (((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 0xdc;
    return;
  }
  return;
}

void SolAct_ggxGrandViperLand(CHARACTER_WORK *offset) // FUN_00651ee0
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x6d);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 1;
  }
  return;
}

void SolAct_ggxGrandViperDrop(CHARACTER_WORK *offset) // FUN_00651f30
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x6c);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  SetLandBreakActno(offset,0x3006d);
  return;
}

void SolAct_ggxGrandViperJump(CHARACTER_WORK *offset) // FUN_00651f70
{
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x6b);
    offset->InstSt = offset->InstSt & 0xffdf;
    SetLandBreakActno(offset,0xffffffff);
    return;
  }
  if ((-0x1f5 < offset->yspeed) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 0x3006c;
  }
  SetLandBreakActno(offset,0xffffffff);
  return;
}

void SolAct_GrandViperOut(CHARACTER_WORK *offset) // FUN_00651fd0
{
  offset->actst = offset->actst & 0xfffffbff;
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0xb1);
    offset->InstSt = offset->InstSt & 0xffdf;
  }
  if (((offset->InstSt & 0xc8) != 0) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 0x3006b;
  }
  return;
}

void SolAct_GrandViper(CHARACTER_WORK *offset) // FUN_00652020 - WIP
{
  short *psVar1;
  int iVar2;
  PLAYER_ENTRY *pPVar3;
  
  offset->actst = offset->actst & 0xfffffbff;
  offset->CommandFlag = 0xc05f;
  if ((offset->InstSt & 0x20) != 0)
  {
    SetAnimeNo(offset,0x6a);
    offset->InstSt = offset->InstSt & 0xffdf;
    offset->ply->PersonalWork[0].w[1] = 0;
  }
  if (offset->HitStopTime == '\0')
  {
    if ((GameKey[offset->padid].trg & 0xa0) != 0)
    {
      psVar1 = offset->ply->PersonalWork[0].w + 1;
      *psVar1 = *psVar1 + 6;
    }
    pPVar3 = offset->ply;
    if ((GameKey[offset->padid].trg & (uint)(ushort)(pPVar3->HeavySlashKey | pPVar3->SlashKey | pPVar3->KickKey | pPVar3->PunchKey)) != 0)
    {
      pPVar3->PersonalWork[0].w[1] = pPVar3->PersonalWork[0].w[1] + 6;
    }
  }
  else
  {
    if ((GameKey[offset->padid].trg & 0xa0) != 0)
    {
      psVar1 = offset->ply->PersonalWork[0].w + 1;
      *psVar1 = *psVar1 + 1;
    }
    pPVar3 = offset->ply;
    if ((GameKey[offset->padid].trg & (uint)(ushort)(pPVar3->HeavySlashKey | pPVar3->SlashKey | pPVar3->KickKey | pPVar3->PunchKey)) != 0)
    {
      pPVar3->PersonalWork[0].w[1] = pPVar3->PersonalWork[0].w[1] + 1;
    }
  }
  pPVar3 = offset->ply;
  if (DAT_00b101f5 != '\0')
  {
    if (0x78 < pPVar3->PersonalWork[0].w[1])
    {
      pPVar3->PersonalWork[0].w[1] = 0;
      FUN_006aaa00(offset);
      if (offset->actnonext == 0xffffffff)
      {
        offset->actnonext = 0x3006a;
      }
    }
    iVar2 = (int)offset->ply->PersonalWork[0].w[1] / 6 + 0x14;
    if (((iVar2 <= (short)offset->ActTimer) && ((short)offset->ActTimer - iVar2 != -1)) && (offset->actnonext == 0xffffffff))
    {
      offset->actnonext = 0x30127;
    }
    psVar1 = offset->ply->PersonalWork[0].w + 1;
    *psVar1 = *psVar1 + 2;
    return;
  }
  if (0x78 < pPVar3->PersonalWork[0].w[1])
  {
    pPVar3->PersonalWork[0].w[1] = 0x78;
  }
  iVar2 = (int)offset->ply->PersonalWork[0].w[1] / 6 + 0x14;
  if (((iVar2 <= (short)offset->ActTimer) && ((short)offset->ActTimer - iVar2 != -1)) && (offset->actnonext == 0xffffffff))
  {
    offset->actnonext = 0x30127;
  }
  return;
}
