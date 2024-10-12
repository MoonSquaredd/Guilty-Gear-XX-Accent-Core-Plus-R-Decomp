int RandomSeed;
int BattleStatus;
code *IsDeadCheck;

void CmnAct_Stand(CHARACTER_WORK *offset)
{
  ushort animNo;
  uint rng;
  CHARACTER_WORK *object;
  
  offset->CommandFlag = 0x101;
  offset->actst = offset->actst & 0xffffefef | 0x40000;
  offset->yspeed = 0;
  offset->ply->ActChangeInterrupt = IsDeadCheck;
  if ((offset->InstSt & 0x20) != 0)
  {
    animNo = SetChangeFrameAnime(offset,0);
    SetAnimeNo(offset,(uint)animNo);
    offset->InstSt = offset->InstSt & 0xffdf;
    offset->xspeed = 0;
  }
  if (BattleStatus == 3)
  {
    return;
  }
  if (BattleStatus == 4)
  {
    return;
  }
  if (((g_info.mode & 0x4000) != 0) && (story.is_enter != 0))
  {
    return;
  }
  switch(offset->idno)
  {
  case 1:
  case 5:
  case 0xc:
  case 0xf:
  case 0x11:
  case 0x12:
  case 0x15:
  case 0x16:
    if ((offset->InstSt & 0x80) == 0)
    {
      return;
    }
    rng = Random(&RandomSeed);
    if ((rng & 7) != 0)
    {
      return;
    }
    break;
  case 0xb:
    if ((offset->InstSt & 0x80) == 0)
    {
      return;
    }
    object = SearchObjectWork(offset,0x52);
    rng = Random(&RandomSeed);
    if ((rng & 7) != 0)
    {
      return;
    }
    if (object->actno != 0)
    {
      return;
    }
    if (offset->ply->PersonalWork[0].l != 0)
    {
      return;
    }
    if (offset->actnonext != 0xffffffff)
    {
      return;
    }
    offset->actnonext = 0x80091;
    return;
  case 0xd:
    if ((offset->InstSt & 0x80) == 0)
    {
      return;
    }
    rng = Random(&RandomSeed);
    if ((rng & 7) != 0)
    {
      rng = Random(&RandomSeed);
      if ((rng & 7) != 0)
      {
        return;
      }
      if (offset->actnonext != 0xffffffff)
      {
        return;
      }
      offset->actnonext = 0x800b2;
      return;
    }
  default:
    return;
  }
  if (offset->actnonext == 0xffffffff)
  {
    offset->actnonext = 0x8003d;
    return;
  }
