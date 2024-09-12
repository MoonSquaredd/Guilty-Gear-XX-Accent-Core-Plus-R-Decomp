void SetAnimeNoLoop(CHARACTER_WORK *offset,int no) // FUN_006afc20
{
  TACTHEADER *pTVar1;
  uchar uVar2;
  uchar uVar3;
  
  offset->AnimeNo = (short)no;
  if (offset->InstTb != (uint *)0x0)
  {
    pTVar1 = (TACTHEADER *)offset->InstTb[no];
    offset->ActHeaderp = pTVar1;
    (offset->ActHeader).flag = pTVar1->flag;
    uVar2 = pTVar1->damage;
    uVar3 = pTVar1->flag2;
    (offset->ActHeader).lvflag = pTVar1->lvflag;
    (offset->ActHeader).damage = uVar2;
    (offset->ActHeader).flag2 = uVar3;
    SetDamage(offset,(ushort)(offset->ActHeader).damage);
    offset->InstAddr = (int *)(offset->ActHeaderp + 1);
    offset->InstSt = 2;
  }
  return;
}

void ExeAnime(CHARACTER_WORK *offset) // FUN_006b1c20
{
  ushort uVar1;
  
  if ((((offset->HitStopTime == '\0') || (-1 < offset->ColliFlag)) || ((offset->InstSt & 0x100U) != 0)) && (((offset->actst & 0x400000) == 0 || (offset->actst = offset->actst & 0xffbfffff, (offset->InstSt & 0x100U) != 0))))
  {
    uVar1 = offset->InstSt;
    if ((uVar1 & 2) == 0)
    {
      offset->InstSt = uVar1 & 0xfffb;
    }
    else
    {
      if ((uVar1 & 8) == 0)
      {
        if (offset->ply != (PLAYER_ENTRY *)0x0)
        {
          offset->ply->PosByEnemyAddr = (void *)0x0;
        }
        NextInstExecute(offset);
      }
      offset->InstSt = offset->InstSt & 0xfefdU | 4;
    }
    if (offset->HitStopTime == '\0')
    {
      offset->AnimeTime = offset->AnimeTime + 1;
      if ((ushort)offset->AnimeTime < (ushort)offset->AnimeRate)
      {
        if ((ushort)offset->AnimeTime + 1 == (uint)offset->AnimeRate)
        {
          uVar1 = offset->InstSt;
          if ((uVar1 & 1) != 0)
          {
            if ((~uVar1 & 0x10) != 0)
            {
              offset->InstSt = uVar1 | 0x40;
              return;
            }
            offset->InstSt = uVar1 | 0x80;
            return;
          }
        }
        else
        {
          offset->InstSt = offset->InstSt & 0xff3f;
        }
      }
      else
      {
        uVar1 = offset->InstSt;
        offset->InstSt = uVar1 & 0xffbf | 2;
        if ((uVar1 & 1) != 0)
        {
          if ((uVar1 & 0x10) != 0)
          {
            SetAnimeNoLoop(offset,(uint)(ushort)offset->AnimeNo);
            return;
          }
          if ((uVar1 & 0x200) == 0)
          {
            if ((uVar1 & 0x2000) != 0)
            {
              offset->actst = offset->actst | 0x80000000;
              return;
            }
            if ((uVar1 & 0x400) == 0)
            {
              if ((uVar1 & 0x800) == 0)
              {
                if ((uVar1 & 0x1000) == 0)
                {
                  offset->InstSt = uVar1 & 0xffbf | 10;
                  return;
                }
                if (offset->actnonext == 0xffffffff)
                {
                  offset->actnonext = 0;
                  return;
                }
              }
              else if (offset->actnonext == 0xffffffff)
              {
                offset->actnonext = 1;
                return;
              }
            }
            else if (offset->actnonext == 0xffffffff)
            {
              offset->actnonext = 8;
              return;
            }
          }
          else if (offset->actnonext == 0xffffffff)
          {
            offset->actnonext = (uint)(ushort)offset->InstVal;
            return;
          }
        }
      }
    }
  }
  return;
}
