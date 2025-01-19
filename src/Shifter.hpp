#ifndef SHIFTER_HPP
#define SHIFTER_HPP
#include "Turret.hpp"

class Shifter : public Turret
{
public:
    static const int Price;
    Shifter(float x, float y);
    void CreateBullet() override;
    int GetTurretId() const override;
};
#endif // PLUGGUNTURRET_HPP
