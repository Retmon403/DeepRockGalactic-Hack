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
            ImGui::Text(g_language_index ? u8"正在加载内存数据... " : "Loading Data...");
        }
        else {
            ImGui::Text(g_language_index ? u8"【其它】" : "[Other]");
            static const char* items_language[] = { "English",u8"简体中文" };
            ImGui::Combo(u8"Language", &g_language_index, items_language, 2);

            ImGui::Text(u8"<InlineHook:%d> <Fps:%.1f>", hack.GetHookLength(), ImGui::GetIO().Framerate);
            ImGui::Checkbox(g_language_index ? u8"启用功能" : "StartHacker", &on_off.ischange);
            ImGui::SameLine();
            if (ImGui::Checkbox(g_language_index ? u8"调试窗口" : "DbgWindow", &on_off.show_debug)) {
                SetConsoleStatus(on_off.show_debug);
            }
            ImGui::SameLine();
            static bool temp_endgame = false;
            if (ImGui::Checkbox(g_language_index ? u8"结束游戏" : "StopGame", &temp_endgame)) {
                SetConsoleStatus(false);
                hack.CloseProcess(hack.GetParentPID(hack.ProcessId));
                exit(0);
            }
            ImGui::Separator();

            ImGui::Text(g_language_index ? u8"【通用功能】" : "[Common]");
            ImGui::Checkbox(g_language_index ? u8"无限照明弹" : "InfLight", &on_off.infin_light);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"无限投掷物" : "InfGrenades", &on_off.infin_grenade);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"无限子弹" : "InfBullet", &on_off.infin_bullet);
            ImGui::Checkbox(g_language_index ? u8"武器无后坐" : "NoRecoil", &on_off.no_recoil);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"子弹无扩散" : "NoSpread", &on_off.no_spread);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"子弹加速" : "FastBullet", &on_off.bullet_fast);
            ImGui::SliderFloat(g_language_index ? u8"子弹速度值" : "BulletSpeed", &on_off.bullet_fast_float, .0f, 0.1f, "%.2f");
            ImGui::Checkbox(g_language_index ? u8"人物加速" : "FastMove", &on_off.speed_hack);
            ImGui::SliderFloat(g_language_index ? u8"人物速度值" : "MoveSpeed", &on_off.speed_hack_float, 300.f, 1000.f, "%.f");
            ImGui::Separator();

            ImGui::Text(g_language_index ? u8"【辅助功能】" : "[Auto]");
            static int curIndex = 2;
            if (ImGui::Checkbox(g_language_index ? u8"自动开枪（适用于单发类武器）" : "AutoFiring(Suitable for single shot weapons)", &on_off.zcb_auto_firing)) {
                if (!on_off.zcb_auto_firing) {
                    SelectAutoFiring(false);
                }
            }
            const char* items[] = { u8"左键(leftkey)", u8"右键(rightkey)" ,u8"ALT" };
            ImGui::Combo(g_language_index ? u8"开枪快捷键" : "ShortcutKeys", &curIndex, items, 3);
            static int auto_firing[] = { VK_LBUTTON ,VK_RBUTTON ,VK_MENU };
            on_off.zcb_auto_firing_vkcode = auto_firing[curIndex];
            ImGui::Separator();

            ImGui::Text(g_language_index ? u8"【侦察兵】" : "[Scout]");
            ImGui::Checkbox(g_language_index ? u8"抓钩枪无冷却" : "GrappleGun NoCd", &on_off.grapple_cd);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"去除距离限制" : "InfDistance", &on_off.grapple_distance);
            ImGui::Separator();
            ImGui::Text(g_language_index ? u8"【枪手】" : "[Gunners]");
            ImGui::Checkbox(g_language_index ? u8"机枪不过热" : "NoSuperheat", &on_off.gunner_superheat);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"机枪快速启动" : "QuickStart", &on_off.gunner_delay);
            ImGui::Separator();

            ImGui::Text(g_language_index ? u8"【个人物资】" : "[Store]");
            ImGui::Checkbox(g_language_index ? u8"无限代币（买杯啤酒触发）" : "InfMoney(Buy a beer)", &on_off.money);
            ImGui::SameLine();
            ImGui::Checkbox(g_language_index ? u8"无限矿物（购买装备触发）" : "InfOre(Buy a beer)", &on_off.allore);
            ImGui::Checkbox(g_language_index ? u8"无限特长（领取特长点触发）" : "InfSpecial(After obtaining)", &on_off.special_points);
        }

        ImGui::End();
    }
}