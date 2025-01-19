#ifndef BOSSENEMY_HPP
#define BOSSENEMY_HPP
#include "Enemy.hpp"

class BossEnemy : public Enemy {
protected:
    float spawn = 10;
    float count = 10;
public:
    BossEnemy(int x, int y);
    void Update(float deltaTime) override;
};
#endif // REDNORMALENEMY_HPP
