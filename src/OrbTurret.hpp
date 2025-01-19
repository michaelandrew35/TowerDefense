#ifndef ORBTURRET_HPP
#define ORBTURRET_HPP
#include "Turret.hpp"
#include "OrbBullet.hpp"

class OrbTurret : public Turret {
public:
    int cur;
    OrbBullet* bul[4];
    int bulletCount;
    static const int Price;
    OrbTurret(float x, float y);
    void CreateBullet() override;
    int GetTurretId() const override;
    void Shoot(bool check, float reload) override;
    void RemoveBullet();
};
#endif // PLUGGUNTURRET_HPP
