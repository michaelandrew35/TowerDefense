#ifndef TANKENEMY_HPP
#define TANKENEMY_HPP
#include "Enemy.hpp"

class TankEnemy : public Enemy {
public:
    TankEnemy(int x, int y);
    void OnExplode() override;
};
#endif // REDNORMALENEMY_HPP
