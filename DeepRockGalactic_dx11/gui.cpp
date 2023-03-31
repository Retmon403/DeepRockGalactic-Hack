#include "gui.h"
#include "style.hpp"
#include "hacker.h"
#include "dx11hk.h"
#include "memory.h"

bool g_is_show =true;
bool is_debug = false;
int g_language_index = 1;
void GuiMenu() {
    StyleColorsSpectrum();
    if (g_is_show) {
        ImGui::SetNextWindowPos(ImVec2(200, 200), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(400, 530), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowBgAlpha(0.80f);
        ImGui::Begin(u8"DeepRockGalactic HackTool  [Home]Show/Hide", NULL, ImGuiWindowFlags_NoCollapse);
        if (!on_off.isok) {
            ImGui::Text(g_language_index ? u8"���ڼ����ڴ�����... " : "Loading Data...");
        }
        else {
            ImGui::Text(g_language_index ? u8"��������" : "[Other]");
            static const char* items_language[] = { "English",u8"��������" };
            ImGui::Combo(u8"Language", &g_language_index, items_language, 2);

            ImGui::Text(u8"<InlineHook:%d> <Fps:%.1f>", hack.GetHookLength(), ImGui::GetIO().Framerate);
            ImGui::Checkbox(g_language_index ? u8"���ù���" : "StartHacker", &on_off.ischange);
            ImGui::SameLine();
            if (ImGui::Checkbox(g_language_index ? u8"���Դ���" : "DbgWindow", &on_off.show_debug)) {
                SetConsoleStatus(on_off.show_debug);
            }
            ImGui::SameLine();
            static bool temp_endgame = false;
            if (ImGui::Checkbox(g_language_index ? u8"������Ϸ" : "StopGame", &temp_endgame)) {
                SetConsoleStatus(false);
                hack.CloseProcess(hack.GetParentPID(hack.ProcessId));
                exit(0);
            }
            ImGui::Separator();

            ImGui::Text(g_language_index ? u8"��ͨ�ù��ܡ�" : "[Common]");
            ImGui::Checkbox(g_language_index ? u8"����������" : "InfLight", &on_off.infin_light);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"����Ͷ����" : "InfGrenades", &on_off.infin_grenade);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"�����ӵ�" : "InfBullet", &on_off.infin_bullet);
            ImGui::Checkbox(g_language_index ? u8"�����޺���" : "NoRecoil", &on_off.no_recoil);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"�ӵ�����ɢ" : "NoSpread", &on_off.no_spread);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"�ӵ�����" : "FastBullet", &on_off.bullet_fast);
            ImGui::SliderFloat(g_language_index ? u8"�ӵ��ٶ�ֵ" : "BulletSpeed", &on_off.bullet_fast_float, .0f, 0.1f, "%.2f");
            ImGui::Checkbox(g_language_index ? u8"�������" : "FastMove", &on_off.speed_hack);
            ImGui::SliderFloat(g_language_index ? u8"�����ٶ�ֵ" : "MoveSpeed", &on_off.speed_hack_float, 300.f, 1000.f, "%.f");
            ImGui::Separator();

            ImGui::Text(g_language_index ? u8"���������ܡ�" : "[Auto]");
            static int curIndex = 2;
            if (ImGui::Checkbox(g_language_index ? u8"�Զ���ǹ�������ڵ�����������" : "AutoFiring(Suitable for single shot weapons)", &on_off.zcb_auto_firing)) {
                if (!on_off.zcb_auto_firing) {
                    SelectAutoFiring(false);
                }
            }
            const char* items[] = { u8"���(leftkey)", u8"�Ҽ�(rightkey)" ,u8"ALT" };
            ImGui::Combo(g_language_index ? u8"��ǹ��ݼ�" : "ShortcutKeys", &curIndex, items, 3);
            static int auto_firing[] = { VK_LBUTTON ,VK_RBUTTON ,VK_MENU };
            on_off.zcb_auto_firing_vkcode = auto_firing[curIndex];
            ImGui::Separator();

            ImGui::Text(g_language_index ? u8"��������" : "[Scout]");
            ImGui::Checkbox(g_language_index ? u8"ץ��ǹ����ȴ" : "GrappleGun NoCd", &on_off.grapple_cd);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"ȥ����������" : "InfDistance", &on_off.grapple_distance);
            ImGui::Separator();
            ImGui::Text(g_language_index ? u8"��ǹ�֡�" : "[Gunners]");
            ImGui::Checkbox(g_language_index ? u8"��ǹ������" : "NoSuperheat", &on_off.gunner_superheat);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"��ǹ��������" : "QuickStart", &on_off.gunner_delay);
            ImGui::Separator();

            ImGui::Text(g_language_index ? u8"���������ʡ�" : "[Store]");
            ImGui::Checkbox(g_language_index ? u8"���޴��ң���ơ�ƴ�����" : "InfMoney(Buy a beer)", &on_off.money);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"���޿������װ��������" : "InfOre(Buy a beer)", &on_off.allore);
            ImGui::Checkbox(g_language_index ? u8"�����س�����ȡ�س��㴥����" : "InfSpecial(After obtaining)", &on_off.special_points);
        }

        ImGui::End();
    }
}