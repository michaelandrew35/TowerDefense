#ifndef ORBBULLET_HPP
#define ORBBULLET_HPP
#include "Sprite.hpp"

class Enemy;
class Turret;
class PlayScene;
namespace Engine {
    struct Point;
}  // namespace Engine

class OrbBullet : public Engine::Sprite {
protected:
    float speed, dmg, OrbRad, parposx, parposy;
    Turret* parent;
    PlayScene* getplayScene();
public:
    Enemy* target = nullptr;
    explicit OrbBullet(std::string img, float speed, float damage, Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent, float OrbitalRadius);
    void OnExplode(Enemy* enemy);
    void Update(float deltaTime) override;
    void Remove(int idx);
};
#endif // WOODBULLET_HPP
