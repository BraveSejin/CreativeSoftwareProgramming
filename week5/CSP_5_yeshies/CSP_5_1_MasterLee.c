
static char name[] = "마스터 이";

// 능력치는 맨 앞부터 각각 STR, DEX, CON, INT, WIS, CHA를 의미해요.
// 능력치의 총합은 100이어야 해요.
static int stat[] = { 5, 15, 5, 30, 40, 5 };


const char *GetNameOf_MasterLee()
{
	return name;
}


const int *GetStatOf_MasterLee()
{
	return stat;
}

