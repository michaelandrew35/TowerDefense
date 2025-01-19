#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Turret.hpp"
#include "GameEngine.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "OrbBullet.hpp"
#include "OrbTurret.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "LOG.hpp"

using namespace Engine;
PlayScene* OrbBullet::getplayScene()
{
    return dynamic_cast<PlayScene*>(GameEngine::GetInstance().GetActiveScene());
}

OrbBullet::OrbBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent, float OrbitalRadius) :
    Sprite(img, position.x, position.y), speed(speed), dmg(damage), parent(parent), OrbRad(OrbitalRadius) {
    // TODO 3 (2/5): You can imitate the 2 files: 'WoodBullet.hpp', 'WoodBullet.cpp' to create a new bullet.
    Velocity = forwardDirection.Normalize() * speed;
    Rotation = rotation;
    parposx = parent->Position.x;
    parposy = parent->Position.y;
    CollisionRadius = 5;
}
void OrbBullet::OnExplode(Enemy* enemy) {

}
void OrbBullet::Update(float deltaTime)
{
    Sprite::Update(deltaTime);
    PlayScene* scene = getplayScene();
    if (!scene) return;
    Rotation += ((speed / OrbRad) * deltaTime);

    float posx, posy;
    posx = parposx + (OrbRad * cos(Rotation));
    posy = parposy + (OrbRad * sin(Rotation));
    Position = Point(posx, posy);

    for (auto& it : scene->EnemyGroup->GetObjects())
    {
        Enemy* enemy = dynamic_cast<Enemy*>(it);
        if (!enemy->Visible) continue;
        if (Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius))
        {
            dynamic_cast<OrbTurret*>(parent)->bulletCount -= 1;
            OnExplode(enemy);
            enemy->Hit(dmg);
            for (int i = 0; i < 4; i++)
            {
                if (dynamic_cast<OrbTurret*>(parent)->bul[i] == this)
                {
                    dynamic_cast<OrbTurret*>(parent)->bul[i] = NULL;
                }
            }
            getplayScene()->BulletGroup->RemoveObject(objectIterator);
            return;
        }
    }
}
void OrbBullet::Remove(int idx)
{
    dynamic_cast<OrbTurret*>(parent)->bul[idx] = NULL;
    getplayScene()->BulletGroup->RemoveObject(objectIterator);
}