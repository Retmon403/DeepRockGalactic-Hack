#include "memory.h"
#include "game_hex.h"

GAME_MEMORY_ADDR g_memory_addr = { 0 };
GAME_MEMORY_HOOK g_memory_hook = { 0 };
FUNC_BOX g_box = { 0 };
ULONG64 g_modbase = 0;
DWORD g_modsize = 0;
FLOAT g_hook_bullet_speed = 0.0f;
bool loading_addr = false;
Memory memory;

void switch_lighting(bool no_off)
{
    char buf[] = { 0xff,0xc9 };
    char buf_cd[] = { 0x0F,0x82,0xA6,0x00,0x00,0x00 };
    if (no_off)
    {
        memory.WriteHex0x90(g_memory_addr.lighting, 2);
        memory.write_memory_0x90(g_memory_addr.lighting_cd, 6);
    }
    else
    {
        memory.write_memory(g_memory_addr.lighting, buf, sizeof(buf));
        memory.write_memory(g_memory_addr.lighting_cd, buf_cd, sizeof(buf_cd));
    }
}

void switch_grenades(bool no_off)
{
    char buf[] = { 0xff,0xc8 };
    if (no_off)
    {
        memory.write_memory_0x90(g_memory_addr.grenades, 2);
    }
    else
    {
        memory.write_memory(g_memory_addr.grenades, buf, sizeof(buf));
    }
}

void switch_grapple_gun(bool no_off)
{
    char buf[] = { 0x89 ,0x81,0xD8,0x00,0x00,0x00 };
    char buf_1[] = { 0x74 ,0x63 };
    if (no_off)
    {
        memory.write_memory_0x90(g_memory_addr.grapple_gun_cd, 6);
        memory.write_memory_0x90(g_memory_addr.grapple_gun_distance, 2);
    }
    else
    {
        memory.write_memory(g_memory_addr.grapple_gun_cd, buf, sizeof(buf));
        memory.write_memory(g_memory_addr.grapple_gun_distance, buf_1, sizeof(buf_1));
    }
}

void switch_jump_plus(bool no_off)
{
    char hook_code[] = { 0xC7,0x87,0x44,0x03,0x00,0x00,0xFF,0xE0,0xF5,0x05,0x8B,0x87,0x44,0x03,0x00,0x00,0x39,
    0x87,0x48,0x03,0x00,0x00,0x0F,0x9C,0xC0 };
    //C7 87 44 03 00 00 FF E0 F5 05 8B 87 44 03 00 00 39 87 48 03 00 00 0F 9C C0
    if (no_off)
    {
        memory.set_generic_hook(g_memory_hook.jump_plus, 15, hook_code, sizeof(hook_code));
    }
    else
    {
        memory.un_generic_hook(g_memory_hook.jump_plus, code_jump_plus, sizeof(code_jump_plus));
    }
}

void switch_pistol_bullet(bool no_off)
{
    char buf[] = { 0x89,0x81,0x58,0x06,0x00,0x00 };
    char buf_1[] = { 0x89,0x86,0x58,0x06,0x00,0x00 };
    char buf_2[] = { 0xF3,0x0F,0x11,0x8E,0x80,0x04,0x00,0x00 };
    if (no_off)
    {
        memory.write_memory_0x90(g_memory_addr.pistol_bullet, 6);
        memory.write_memory_0x90(g_memory_addr.bullet_Gunman_1, 6);
        memory.write_memory_0x90(g_memory_addr.drilling_bit, 8);
    }
    else
    {
        memory.write_memory(g_memory_addr.pistol_bullet, buf, sizeof(buf));
        memory.write_memory(g_memory_addr.bullet_Gunman_1, buf_1, sizeof(buf_1));
        memory.write_memory(g_memory_addr.drilling_bit, buf_2, sizeof(buf_2));
    }
}
void switch_bullet_Gunman(bool no_off)
{
    char buf[] = { 0xF3,0x44,0x0F,0x11,0x86,0x08,0x07,0x00,0x00,0x90,0x90,0x90,0x90 };
    char buf_remov[] = { 0xF3,0x41,0x0F,0x5D,0xC0,0xF3,0x0F,0x11,0x86,0x08,0x07,0x00,0x00 };
    char buf_1[] = { 0xF3,0x0F,0x11,0x83,0xC4,0x02,0x00,0x00 };
    if (no_off)
    {
        rd_memory.write_memory(g_memory_addr.bullet_Gunman_2, buf, sizeof(buf));
        rd_memory.write_memory_0x90(g_memory_addr.bullet_Gunman_3, 8);
    }
    else
    {
        rd_memory.write_memory(g_memory_addr.bullet_Gunman_2, buf_remov, sizeof(buf_remov));
        rd_memory.write_memory(g_memory_addr.bullet_Gunman_3, buf_1, sizeof(buf_1));
    }
}
void switch_quick_install_artillery(bool no_off)
{
    char buf[] = { 0x72,0x74 };
    char remov_limit[] = { 0x89,0x87 ,0xA8,0x03,0x00,0x00 };
    char mov_bullet = 0x89;
    char remov_bullet = 0x39;
    if (no_off)
    {
        rd_memory.write_memory_0x90(g_memory_addr.engineer_quick_install_artillery, 2);
        
        rd_memory.write_memory_0x90(g_memory_addr.engineer_artillery_limit, 6);
        rd_memory.write_memory(g_memory_addr.engineer_artillery_bullet, &mov_bullet, sizeof(mov_bullet));

    }
    else
    {
        rd_memory.write_memory(g_memory_addr.engineer_quick_install_artillery, buf, sizeof(buf));
        
        rd_memory.write_memory(g_memory_addr.engineer_artillery_limit, remov_limit, sizeof(remov_limit));
        rd_memory.write_memory(g_memory_addr.engineer_artillery_bullet, &remov_bullet, sizeof(remov_bullet));
    }

}

void switch_bullet_speed(bool no_off)
{
    char hook_buf[] = { 0xF3,0x41,0x0F,0x5C,0xC1,0x0F,0x2F,0xF8,0x48,0xB8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xF3,
    0x0F,0x10,0x00,0xF3,0x41,0x0F,0x11,0x86,0x80,0x06,0x00,0x00 };
    //F3 41 0F 5C C1 0F 2F F8 48 B8 0 0 0 0 0 0 0 0 F3 0F 10 00 F3 41 0F 11 86 80 06 00 00
    ULONG64 f_addr = (ULONG64)&g_hook_bullet_speed;
    *(PULONG64)(hook_buf + 10) = f_addr;
    if (no_off)
    {

        memory.set_generic_hook(g_memory_hook.bullet_speed, 17, hook_buf, sizeof(hook_buf));
    }
    else
    {
        memory.un_generic_hook(g_memory_hook.bullet_speed, code_bullet_speed, sizeof(code_bullet_speed));
    }
}


void get_module_infor(DWORD pid, const char* mod_name, PULONG64 mod_base, PDWORD mod_size)
{
    HANDLE hpr = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (!hpr)return;
    HMODULE  mod_buf[500] = { 0 };
    DWORD lpdword = 0;
    CHAR name_buf[256] = { 0 };
    EnumProcessModulesEx(hpr, mod_buf, 500 * sizeof(HMODULE), &lpdword, LIST_MODULES_ALL);
    MODULEINFO mod_info = { 0 };
    for (size_t i = 0; i < lpdword / sizeof(HMODULE); i++)
    {
        GetModuleBaseNameA(hpr, mod_buf[i], name_buf, 256);
        if (strcmp(mod_name, name_buf) == 0)
        {
            GetModuleInformation(hpr, mod_buf[i], &mod_info, sizeof(MODULEINFO));
            *mod_base = (ULONG64)mod_buf[i];
            *mod_size = mod_info.SizeOfImage;
            CloseHandle(hpr);
            return;
        }
    }
    CloseHandle(hpr);
}

ULONG64 g_hook_bullet_speed_addr = 0;
FLOAT g_write_bullet_speed = (FLOAT)0.05;

void load_game_addr()
{
    Memory WriteReadProcess;
    ULONG64 retaddr = 0;
    DWORD length = 0;
    get_module_infor(WriteReadProcess.pid, "FSD-Win64-Shipping.exe", &g_modbase, &g_modsize);
    debug_printf_red("modbase:%p,modsize:%p\n\n", g_modbase, g_modsize);


    bool load_ok = false;
    do
    {
        if (g_memory_addr.lighting == 0)
        {
            WriteReadProcess.SearchMemory(code_lighting, sizeof(code_lighting), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.lighting = retaddr - 2;
                debug_printf_green("lighting addr:%p\n\n", g_memory_addr.lighting);
            }
        }
        if (g_memory_addr.lighting_cd == 0)
        {
            WriteReadProcess.SearchMemory(code_lighting_cd, sizeof(code_lighting_cd), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.lighting_cd = retaddr - 6;
                debug_printf_green("lighting_cd addr:%p\n\n", g_memory_addr.lighting_cd);
            }
        }

        if (g_memory_addr.grenades == 0)
        {
            WriteReadProcess.SearchMemory(code_grenades, sizeof(code_grenades), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.grenades = retaddr - 2;
                debug_printf_green("grenades addr:%p\n\n", g_memory_addr.grenades);
            }
        }

       

        if (g_memory_addr.bullet_Gunman_1 == 0)
        {
            WriteReadProcess.SearchMemory(code_bullet_Gunman_1, sizeof(code_bullet_Gunman_1), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.bullet_Gunman_1 = retaddr + sizeof(code_bullet_Gunman_1);
                debug_printf_green("bullet_Gunman_1 addr:%p\n\n", g_memory_addr.bullet_Gunman_1);
            }
        }
        if (g_memory_addr.bullet_Gunman_2 == 0)
        {
            WriteReadProcess.SearchMemory(code_bullet_Gunman_2, sizeof(code_bullet_Gunman_2), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.bullet_Gunman_2 = retaddr + sizeof(code_bullet_Gunman_2);
                debug_printf_green("bullet_Gunman_2 addr:%p\n\n", g_memory_addr.bullet_Gunman_2);
            }
        }
        if (g_memory_addr.bullet_Gunman_3 == 0)
        {
            WriteReadProcess.SearchMemory(code_bullet_Gunman_3, sizeof(code_bullet_Gunman_3), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.bullet_Gunman_3 = retaddr + sizeof(code_bullet_Gunman_3);
                debug_printf_green("bullet_Gunman_3 addr:%p\n\n", g_memory_addr.bullet_Gunman_3);
            }
        }

        if (g_memory_addr.grapple_gun_cd == 0)
        {
            WriteReadProcess.SearchMemory(code_grapple_gun, sizeof(code_grapple_gun), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.grapple_gun_cd = retaddr - 6;
                debug_printf_green("grapple_gun_cd addr:%p\n\n", g_memory_addr.grapple_gun_cd);
            }
        }
        if (g_memory_addr.grapple_gun_distance == 0)
        {
            WriteReadProcess.SearchMemory(code_grapple_gun_distance, sizeof(code_grapple_gun_distance), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.grapple_gun_distance = retaddr - 2;
                debug_printf_green("grapple_gun_distance addr:%p\n\n", g_memory_addr.grapple_gun_distance);
            }
        }
        

        if (g_memory_addr.pistol_bullet == 0)
        {
            WriteReadProcess.SearchMemory(code_pistol_bullet, sizeof(code_pistol_bullet), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.pistol_bullet = retaddr - 6;
                debug_printf_green("pistol_bullet addr:%p\n\n", g_memory_addr.pistol_bullet);
            }
        }

        if (g_memory_addr.drilling_bit == 0)
        {
            WriteReadProcess.SearchMemory(code_drilling_bit, sizeof(code_drilling_bit), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.drilling_bit = retaddr + sizeof(code_drilling_bit);
                debug_printf_green("drilling_bit addr:%p\n\n", g_memory_addr.drilling_bit);
            }
        }
        if (g_memory_addr.engineer_quick_install_artillery == 0)
        {
            WriteReadProcess.SearchMemory(code_quick_install_artillery, sizeof(code_quick_install_artillery), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.engineer_quick_install_artillery = retaddr + sizeof(code_quick_install_artillery);
                debug_printf_green("engineer_quick_install_artillery addr:%p\n\n", g_memory_addr.engineer_quick_install_artillery);
            }
        }

        if (g_memory_addr.engineer_artillery_bullet == 0)
        {
            WriteReadProcess.SearchMemory(code_engineer_artillery_bullet, sizeof(code_engineer_artillery_bullet), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.engineer_artillery_bullet = retaddr - 6;
                debug_printf_green("engineer_artillery_bullet addr:%p\n\n", g_memory_addr.engineer_artillery_bullet);
            }
        }

        if (g_memory_addr.engineer_artillery_limit == 0)
        {
            WriteReadProcess.SearchMemory(code_engineer_artillery_limit, sizeof(code_engineer_artillery_limit), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_addr.engineer_artillery_limit = retaddr - 6;
                debug_printf_green("engineer_artillery_limit addr:%p\n\n", g_memory_addr.engineer_artillery_limit);
            }
        }
        //HOOKS****************************************************************************************************
        if (g_memory_hook.jump_plus == 0)
        {
            WriteReadProcess.SearchMemory(code_jump_plus, sizeof(code_jump_plus), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_hook.jump_plus = retaddr;
                debug_printf_red("hook::jump_plusaddr addr:%p\n\n", g_memory_hook.jump_plus);
            }
        }

        if (g_memory_hook.bullet_speed == 0)
        {
            WriteReadProcess.SearchMemory(code_bullet_speed, sizeof(code_bullet_speed), g_modbase, &retaddr);
            if (retaddr != 0)
            {
                g_memory_hook.bullet_speed = retaddr;
                debug_printf_green("hook::bullet_speed addr:%p\n\n", g_memory_hook.bullet_speed);
            }
        }
        
        load_ok = false;
        for (size_t i = 0; i < sizeof(g_memory_addr) / sizeof(ULONG64); i++)
        {
            if (*(PULONG64)((ULONG64)&g_memory_addr + (ULONG64)i * sizeof(ULONG64)) == 0)
            {
                load_ok = true;
                break;
            }
        }
    } while (load_ok);
    loading_addr = true;
    switch_bullet_speed(true);
}