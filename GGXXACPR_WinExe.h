union PERSONALWORK {
  int l;
  short w[2];
  char b[4];
  unsigned int ul;
  unsigned short uw[2];
  unsigned char ub[4];
  float f;
};

struct COLLISION {
  short x;
  short y;
  unsigned short w;
  unsigned short h;
  unsigned int attr;
};

struct DAMAGEPARAM  //unfinished
  unsigned short DownX;
  unsigned short DownY;
  unsigned short DownGravity;
  unsigned short DownUkemiTime;
  unsigned short FaintPoint;
  // 6 undef
  unsigned short Kezuri;
  unsigned short DamageHosei;
  // 8 undef
  unsigned char dno;
  unsigned char dprob;
  unsigned char gno;
  unsigned char gprob;
  // 65 undef
};

struct PLAYER_ENTRY { //unfinished
  unsigned short Tension;
  char ShakeTime;
  char BackStepInvalid;
  // 6 undef
  short pactst;
  int homingtime;
  // 4 undef
  int offx;
  unsigned short notThrowTime;
  // 4 undef
  unsigned short DownTimer;
  unsigned char HomingJumpDir;
  // 9 undef
  char MutekiTime;
  // 5 undef
  short TensionPenaltyTime;
  // 10 undef
  char TensionMovePenaltyTime;
  char JustGuardTime;
  char JustGuardIgnoreTime;
  char JustGuardWhiteTime;
  // 8 undef
  unsigned short PunchKey;
  unsigned short KickKey;
  unsigned short SlashKey;
  unsigned short HeavySlashKey;
  // 34 undef
  unsigned short JumpFlag;
  unsigned int chainflag;
  // 4 undef
  unsigned short FaintPoint;
  unsigned short FaintTime;
  // 5 undef
  unsigned char CPU;
  char sousaitime;
  // 1 undef
  union PERSONALWORK PersonalWork[4];
  // 20 undef
  int DownFlag;
  // 36 undef
  void *PosByEnemyAddr;
  unsigned char OverkillFlag;
  // 1 undef
  unsigned char DustTime;
  // 21 undef
  unsigned char AttackDown;
  unsigned char DefenceDown;
  unsigned char JumpSeal;
  unsigned char ArtsSeal;
  unsigned char Poison;
  unsigned char MistTime;
  short DamageTime;
  // 73 undef
};

struct TACTHEADER {
  unsigned int flag;
  unsigned short lvflag;
  unsigned char damage;
  unsigned char flag2;
};

struct CHARACTER_WORK { //unfinished
  unsigned short idno;
  unsigned char dirflag;
  unsigned char posdirflag;
  // 8 undef
  unsigned int actst;
  unsigned int actnonext;
  // 4 undef
  short actno;
  unsigned short Localid;
  unsigned short ActTimer;
  unsigned short HitPoint;
  void *parentWork;
  short actnoSv;
  // 1 undef
  unsigned char padid;
  short parentFlag;
  short GuardSt;
  PLAYER_ENTRY *ply;
  // 4 undef
  unsigned int attackst;
  unsigned int CommandFlag;
  // 4 undef
  short CellNo;
  // 2 undef
  short ImageNo;
  // 2 undef
  unsigned int * GclTop;
  // 4 undef
  unsigned short scaleY;
  unsigned short scale;
  // 4 undef
  COLLISION *ExColliAddr;
  char ColliFlag;
  // 1 undef
  char DamColliFlag;
  // 1 undef
  unsigned short TensionAdd;
  // 34 undef
  char ColliCnt;
  // 3 undef
  DAMAGEPARAM *HitParam;
  // 28 undef
  unsigned short transmode;
  // 2 undef
  unsigned int SpriteFlag;
  int posx;
  int posy;
  int xspeed;
  int yspeed;
  // 8 undef
  int HitBackx;
  int RHitBackx;
  // 4 undef
  int gravity;
  unsigned short parentx;
  unsigned short parenty;
  unsigned short angle;
  unsigned short priority;
  unsigned int InstTb;
  TACTHEADER ActHeader;
  TACTHEADER *ActHeaderp;
  int *InstAddr;
  short InstSt;
  short InstVal;
  short AnimeNo;
  short AnimeTime;
  unsigned char AnimeRate;
  unsigned char HitStopTime;
  // 1 undef
  unsigned short Mark;
  unsigned char MaxHitCount;
  unsigned short trans;
  unsigned int LandBreakActno;
  // 24 undef
};

struct CREATE_ARG {
  int flag;
  int x;
  int y;
  int tx;
  int ty;
  unsigned short actno;
  short Localid;
  unsigned short angle;
  unsigned short padd;
};
