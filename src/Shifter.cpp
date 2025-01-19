#include "Shifter.hpp"


const int Shifter::Price = 0;
Shifter::Shifter(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/shifter.png", "play/invisible.png", x, y, 100, Price, 0) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void Shifter::CreateBullet() {}
int Shifter::GetTurretId() const
{
    return 4;
}
