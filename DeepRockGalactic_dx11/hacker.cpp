#include "hacker.h"
#include "memory.h"
#include "GameHex.h"
Memory hack = Memory();

HOOK_OBJ g_hook = { 0 };
ON_OFF on_off = { 0 };

void InitHookConfig() {
	on_off.isok = false;
	on_off.show_debug = true;
	on_off.ischange = false;

	on_off.infin_light = true;//无限照明弹
	on_off.infin_grenade = true;//无限手榴弹
	on_off.infin_bullet = true;//无限子弹
	on_off.no_recoil = true;//无后坐力
	on_off.no_spread = true;//子弹无扩散
	on_off.bullet_fast = true;//子弹加速
	on_off.bullet_fast_float = .0f;//子弹加速 调整
	on_off.grapple_cd = true;//抓钩枪cd
	on_off.grapple_distance = true;//抓钩枪距离限制
	on_off.gunner_delay = true;//枪手加特林延迟
	on_off.gunner_superheat = true;//枪手加特林过热
	on_off.money = true;
	on_off.allore = true;
	on_off.special_points = true;
	on_off.zcb_auto_firing = true;
	on_off.zcb_auto_firing_vkcode = VK_MENU;
	on_off.speed_hack = true;
	on_off.speed_hack_float = 800.f;
	

	g_hook.infin_light.size = 2;
	g_hook.infin_grenade.size = 2;
	g_hook.zbc_bullet.size = 6;
	g_hook.zbc_grapple_cd.size = 6;
	g_hook.grapple_distance.size = 2;
	g_hook.no_recoil.size = 5;
	g_hook.gunner_bullet.size = 6;
	g_hook.gunner_delay.size = 8;
	g_hook.gunner_superheat.size = 8;
	g_hook.Driller_bullet.size = 8;

	g_hook.special_points.size = 2;
	g_hook.zcb_auto_firing.size = 2;
}

void InitHacker() {
	InitHookConfig();
	printf("\n");

	g_hook.infin_light.addr = hack.Search(light_shell, sizeof(light_shell));
	hack.Read(g_hook.infin_light.addr, g_hook.infin_light.old_code, g_hook.infin_light.size);
	printf("照明弹 -> %p\n", g_hook.infin_light.addr);

	g_hook.infin_grenade.addr = hack.Search(grenade_shell, sizeof(grenade_shell));
	hack.Read(g_hook.infin_grenade.addr, g_hook.infin_grenade.old_code, g_hook.infin_grenade.size);
	printf("手榴弹（主机） -> %p\n", g_hook.infin_grenade.addr);

	g_hook.zbc_bullet.addr = hack.Search(zcb_bullet_shell,sizeof(zcb_bullet_shell));
	hack.Read(g_hook.zbc_bullet.addr, g_hook.zbc_bullet.old_code, g_hook.zbc_bullet.size);
	printf("侦察兵子弹 -> %p\n", g_hook.zbc_bullet.addr);

	g_hook.zbc_grapple_cd.addr = hack.Search(zcb_grapple_cd_shell, sizeof(zcb_grapple_cd_shell)) + 10;
	hack.Read(g_hook.zbc_grapple_cd.addr, g_hook.zbc_grapple_cd.old_code, g_hook.zbc_grapple_cd.size);
	printf("侦察兵抓钩CD -> %p\n", g_hook.zbc_grapple_cd.addr);

	g_hook.grapple_distance.addr = hack.Search(zcb_grapple_distance_shell, sizeof(zcb_grapple_distance_shell));
	hack.Read(g_hook.grapple_distance.addr, g_hook.grapple_distance.old_code, g_hook.grapple_distance.size);
	printf("侦察兵抓钩距离限制 -> %p\n", g_hook.grapple_distance.addr);

	g_hook.no_recoil.addr = hack.Search(gun_recoil_shell, sizeof(gun_recoil_shell)) + 10;
	hack.Read(g_hook.no_recoil.addr, g_hook.no_recoil.old_code, g_hook.no_recoil.size);
	printf("武器后坐力 -> %p\n", g_hook.no_recoil.addr);

	g_hook.no_spread.addr = hack.Search(no_spread_shell, sizeof(no_spread_shell)) + 22;
	printf("武器子弹扩散 -> %p\n", g_hook.no_spread.addr);

	g_hook.bullet_fast.addr = hack.Search(zcb_bullet_fast_shell, sizeof(zcb_bullet_fast_shell));
	printf("侦察兵子弹加速 -> %p\n", g_hook.bullet_fast.addr);

	g_hook.gunner_bullet.addr = hack.Search(gunner_bullet_shell, sizeof(gunner_bullet_shell));
	hack.Read(g_hook.gunner_bullet.addr, g_hook.gunner_bullet.old_code, g_hook.gunner_bullet.size);
	printf("枪手加特林子弹 -> %p\n", g_hook.gunner_bullet.addr);

	g_hook.gunner_superheat.addr = hack.Search(gunner_superheat_shell, sizeof(gunner_superheat_shell));
	hack.Read(g_hook.gunner_superheat.addr, g_hook.gunner_superheat.old_code, g_hook.gunner_superheat.size);
	printf("枪手加特林过热 -> %p\n", g_hook.gunner_superheat.addr);

	g_hook.gunner_delay.addr = hack.Search(gunner_delay_shell, sizeof(gunner_delay_shell));
	hack.Read(g_hook.gunner_delay.addr, g_hook.gunner_delay.old_code, g_hook.gunner_delay.size);
	printf("枪手加特林开枪延迟 -> %p\n", g_hook.gunner_delay.addr);

	g_hook.Driller_bullet.addr = hack.Search(Driller_bullet_shell, sizeof(Driller_bullet_shell));
	hack.Read(g_hook.Driller_bullet.addr, g_hook.Driller_bullet.old_code, g_hook.Driller_bullet.size);
	printf("钻机手燃料 -> %p\n", g_hook.Driller_bullet.addr);

	g_hook.money.addr = hack.Search(money_shell, sizeof(money_shell)) + 20;
	printf("代币 -> %p\n", g_hook.money.addr);

	g_hook.allore.addr = hack.Search(allore_shell, sizeof(allore_shell)) + 31;
	printf("所有矿物 -> %p\n", g_hook.allore.addr);
	
	g_hook.special_points.addr = hack.Search(special_points_shell, sizeof(special_points_shell));
	hack.Read(g_hook.special_points.addr, g_hook.special_points.old_code, g_hook.special_points.size);
	printf("特长 -> %p\n", g_hook.special_points.addr);


	g_hook.zcb_auto_firing.addr = hack.Search(zcb_auto_firing_shell, sizeof(zcb_auto_firing_shell)) + 7;
	hack.Read(g_hook.zcb_auto_firing.addr, g_hook.zcb_auto_firing.old_code, g_hook.zcb_auto_firing.size);
	printf("自动开火 -> %p\n", g_hook.zcb_auto_firing.addr);

	g_hook.speed_hack.addr = hack.Search(speed_hack_shell, sizeof(speed_hack_shell)) + 18;
	hack.Read(g_hook.speed_hack.addr, g_hook.speed_hack.old_code, g_hook.speed_hack.size);
	printf("人物加速 -> %p\n", g_hook.speed_hack.addr);

	
	on_off.isok = true;
	CloseHandle(CreateThread(0, 0, ReChange, 0, 0, 0));
	CloseHandle(CreateThread(0, 0, AutoFiring, 0, 0, 0));
}

DWORD ReChange(LPVOID lp) {
	while (true) {
		if (on_off.ischange) {

			if (on_off.infin_light) 
				hack.WriteHex0x90(g_hook.infin_light.addr, g_hook.infin_light.size);
			else 
				hack.Write(g_hook.infin_light.addr, g_hook.infin_light.old_code, g_hook.infin_light.size);


			if (on_off.infin_grenade)
				hack.WriteHex0x90(g_hook.infin_grenade.addr, g_hook.infin_grenade.size);
			else
				hack.Write(g_hook.infin_grenade.addr, g_hook.infin_grenade.old_code, g_hook.infin_grenade.size);


			if (on_off.infin_bullet) {
				//侦察兵子弹
				hack.WriteHex0x90(g_hook.zbc_bullet.addr, g_hook.zbc_bullet.size);
				//枪手加特林子弹
				hack.WriteHex0x90(g_hook.gunner_bullet.addr, g_hook.gunner_bullet.size);
				//钻机手钻头燃料
				hack.WriteHex0x90(g_hook.Driller_bullet.addr, g_hook.Driller_bullet.size);
			}
			else {
				hack.Write(g_hook.zbc_bullet.addr, g_hook.zbc_bullet.old_code, g_hook.zbc_bullet.size);
				hack.Write(g_hook.gunner_bullet.addr, g_hook.gunner_bullet.old_code, g_hook.gunner_bullet.size);
				hack.Write(g_hook.Driller_bullet.addr, g_hook.Driller_bullet.old_code, g_hook.Driller_bullet.size);
			}

			if (on_off.grapple_cd)
				hack.WriteHex0x90(g_hook.zbc_grapple_cd.addr, g_hook.zbc_grapple_cd.size);
			else
				hack.Write(g_hook.zbc_grapple_cd.addr, g_hook.zbc_grapple_cd.old_code, g_hook.zbc_grapple_cd.size);


			if (on_off.grapple_distance) 
				hack.WriteHex0x90(g_hook.grapple_distance.addr, g_hook.grapple_distance.size);
			else
				hack.Write(g_hook.grapple_distance.addr, g_hook.grapple_distance.old_code, g_hook.grapple_distance.size);

			if (on_off.no_recoil) {
				UCHAR no_recoil_temp[] = { 0xc3,0x90,0x90,0x90,0x90 };
				hack.Write(g_hook.no_recoil.addr, no_recoil_temp, sizeof(no_recoil_temp));
			}
			else
				hack.Write(g_hook.no_recoil.addr, g_hook.no_recoil.old_code, g_hook.no_recoil.size);


			if (on_off.no_spread) {
				static UCHAR old_command_no_spread[] = { 0xC7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
				if (!g_hook.no_spread.size) {
					g_hook.no_spread.size = 1;
					hack.Read((PVOID)(g_hook.no_spread.addr + 8), (PVOID)(old_command_no_spread + 1), 5);
				}
				UCHAR no_recoil_temp[] = { 0xc3,0x90,0x90,0x90,0x90 };
				hack.SetHookByLongJump(g_hook.no_spread.addr, 17, old_command_no_spread, sizeof(old_command_no_spread));
			}
			else
				hack.UnHookByLongJump(g_hook.no_spread.addr);


			if (on_off.bullet_fast) {
				UCHAR bullet_speed[] = { 0x50,0x48,0xB8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0x0F,0x10,0x00,0x58,0x90 };
				*(PULONG64)(bullet_speed + 3) = (ULONG64)&on_off.bullet_fast_float;
				hack.SetHookByLongJump(g_hook.bullet_fast.addr, 16, bullet_speed, sizeof(bullet_speed));
			}
			else
				hack.UnHookByLongJump(g_hook.bullet_fast.addr);
			

			if (on_off.gunner_delay)
				hack.WriteHex0x90(g_hook.gunner_delay.addr, g_hook.gunner_delay.size);
			else
				hack.Write(g_hook.gunner_delay.addr, g_hook.gunner_delay.old_code, g_hook.gunner_delay.size);

			if (on_off.gunner_superheat)
				hack.WriteHex0x90(g_hook.gunner_superheat.addr, g_hook.gunner_superheat.size);
			else
				hack.Write(g_hook.gunner_superheat.addr, g_hook.gunner_superheat.old_code, g_hook.gunner_superheat.size);

			if (on_off.money) {
				static UCHAR old_command_money[] = { 0xC7,0x00,0x00,0x00,0x00,0x00,0x3F,0x42,0x0F,0x00 };
				if (!g_hook.money.size) {
					//保证只读取一次
					g_hook.money.size = 1;
					//把代币[xxx+xxx]寄存器寻址偏移字节读出来保存
					hack.Read((PVOID)(g_hook.money.addr + 3), (PVOID)(old_command_money + 1), 5);
				}
				hack.SetHookByLongJump(g_hook.money.addr, 15, old_command_money, sizeof(old_command_money));
			}
			else
				hack.UnHookByLongJump(g_hook.money.addr);

			if (on_off.allore) {
				static UCHAR old_command_ore[] = { 0xC7,0x01,0xF0,0x23,0x74,0x49 };
				if (!g_hook.allore.size) {
					g_hook.allore.size = 1;
					hack.Read((PVOID)(g_hook.allore.addr + 3), (PVOID)(old_command_ore + 1), 1);
				}
				hack.SetHookByLongJump(g_hook.allore.addr, 14, old_command_ore, sizeof(old_command_ore));
			}
			else
				hack.UnHookByLongJump(g_hook.allore.addr);


			if (on_off.special_points) {
				UCHAR write_special_points[] = { 0x01,0x89 };
				hack.Write(g_hook.special_points.addr, write_special_points, sizeof(write_special_points));
			}
			else
				hack.Write(g_hook.special_points.addr, g_hook.special_points.old_code, g_hook.special_points.size);

			if (on_off.speed_hack) {
				/*push rax
				mov rax, xxxxxxxx
				mov rax, [rax]
				mov[rbx + 0000018C], rax
				pop rax*/
				static UCHAR write_speed_hakc[] = { 0x50,0x48,0xB8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0x8B,0x00,0x48,0x89,0x00,0x00,0x00,0x00,0x00,0x58 };
				if (!g_hook.speed_hack.size) {
					g_hook.speed_hack.size = 1;
					hack.Read((PVOID)(g_hook.speed_hack.addr + 3), (PVOID)(write_speed_hakc + 16), 5);
					*(PULONG64)(write_speed_hakc + 3) = (ULONG64) & on_off.speed_hack_float;
				}
				hack.SetHookByLongJump(g_hook.speed_hack.addr, 14, write_speed_hakc, sizeof(write_speed_hakc));
			}
			else
				hack.UnHookByLongJump(g_hook.speed_hack.addr);
		}
		Sleep(1000);
	}
	return 0;
}

DWORD AutoFiring(LPVOID lp) {
	while (true) {
		if (on_off.zcb_auto_firing) {
			if (GetAsyncKeyState(on_off.zcb_auto_firing_vkcode) != 0) {
				SelectAutoFiring(true);
			}
			else {
				SelectAutoFiring(false);
			}
		}
		Sleep(10);
	}
	return 0;
}

void SelectAutoFiring(bool isfiring) {
	isfiring ? hack.WriteHex0x90(g_hook.zcb_auto_firing.addr, g_hook.zcb_auto_firing.size) :
		hack.Write(g_hook.zcb_auto_firing.addr, g_hook.zcb_auto_firing.old_code, g_hook.zcb_auto_firing.size);
}