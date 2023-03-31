#pragma once

#include "define.h"

enum SelectStyle {
    StyleRed,
    StyleGreen,
    StyleBlue,
    StyleOrange
};

void SetSolidColorStyle(SelectStyle);
void SetDarkTheme();
void SetStyleEnemyMouse();
void StyleColorsSpectrum();