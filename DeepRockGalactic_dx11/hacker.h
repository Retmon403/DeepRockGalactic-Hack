#pragma once
#include "define.h"



typedef struct {
	bool isok;
	bool show_debug;
	bool ischange;

	bool infin_light;
	bool infin_grenade;
	bool infin_bullet;
	bool no_recoil;
	bool no_spread;
	bool bullet_fast;
	float bullet_fast_float;
	bool grapple_cd;
	bool grapple_distance;
	
	bool gunner_delay;
	bool gunner_superheat;

	bool money;
	bool allore;
	bool special_points;

	bool zcb_auto_firing;
	int zcb_auto_firing_vkcode;
	bool gunner_auto_firing;

	bool speed_hack;
	float speed_hack_float;
}ON_OFF;


typedef struct {
	PUCHAR addr;
	DWORD size;
	CHAR old_code[50];
}SAVE_CODE;


typedef struct {
	SAVE_CODE infin_light;
	SAVE_CODE infin_grenade;

	SAVE_CODE zbc_bullet;
	SAVE_CODE no_recoil;
	SAVE_CODE no_spread;
	SAVE_CODE bullet_fast;
	SAVE_CODE zbc_grapple_cd;
	SAVE_CODE grapple_distance;

	SAVE_CODE gunner_bullet;
	SAVE_CODE gunner_delay;
	SAVE_CODE gunner_superheat;
	SAVE_CODE Driller_bullet;

	SAVE_CODE money;
	SAVE_CODE allore;
	SAVE_CODE special_points;

	SAVE_CODE zcb_auto_firing;
	SAVE_CODE gunner_auto_firing;
	SAVE_CODE speed_hack;
}HOOK_OBJ;

extern ON_OFF on_off;

void InitHookConfig();
void InitHacker();
DWORD ReChange(LPVOID lp);
DWORD AutoFiring(LPVOID lp);
void SelectAutoFiring(bool isfiring);

extern class Memory hack;