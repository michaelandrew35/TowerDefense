#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "OrbBullet.hpp"
#include "Group.hpp"
#include "OrbTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ShootEffect.hpp"
#include "LOG.hpp"

const int OrbTurret::Price = 60;
OrbTurret::OrbTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/orb-turret.png", x, y, 200, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
    bulletCount = 0;
    cur = 4;
}
void OrbTurret::CreateBullet() {
    PlayScene* scene = getPlayScene();
    if (!scene) return;
    float angle = 50.0f * getPlayScene()->ticks;
    for (int i = 0; i < cur; i++)
    {
        OrbBullet* bullet = new OrbBullet("play/bullet-8.png", 50.0f, 10, Position, Position, i * ALLEGRO_PI / 2, this, 200.0f);
        bul[i] = bullet;
        scene->BulletGroup->AddNewObject(bullet);
        this->bulletCount++;
    }
    cur = 4;
}
int OrbTurret::GetTurretId() const
{
    return 2;
}
void OrbTurret::Shoot(bool check, float reload)
{
    if (bulletCount >= 1) return;
    CreateBullet();
}
void OrbTurret::RemoveBullet()
{
    for (int i = 0; i < 4; i++)
    {
        if (bul[i]) bul[i]->Remove(i);
        Engine::LOG(Engine::INFO) << i;
    }
    Engine::LOG(Engine::INFO) << "PLS";
    this->bulletCount = 0;
    Engine::LOG(Engine::INFO) << "YES";
}