#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "MachineGunBullet.hpp"
#include "Group.hpp"
#include "MachineGunTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ShootEffect.hpp"

const int MachineGunTurret::Price = 80;
MachineGunTurret::MachineGunTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-1.png", x, y, 400, Price, 0.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void MachineGunTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    for (int i = 0; i < this->level; i++)
    {
        Engine::Point pos = Position + normalized * 36 + ((i - (this->level - 1) / 2.0f) * 12.0f) * (Engine::Point(-normalized.y, normalized.x));
        getPlayScene()->BulletGroup->AddNewObject(new MachineGunBullet(pos, diff, rotation, this));
    }
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    getPlayScene()->EffectGroup->AddNewObject(new ShootEffect(Position + normalized * 36));
    AudioHelper::PlayAudio("gun.wav");
}
int MachineGunTurret::GetTurretId() const
{
    return 1;
}
