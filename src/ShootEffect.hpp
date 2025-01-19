#ifndef SHOOTEFFECT_HPP
#define SHOOTEFFECT_HPP
#include <allegro5/bitmap.h>
#include <memory>
#include <vector>

#include "Sprite.hpp"

class PlayScene;

class ShootEffect : public Engine::Sprite {
protected:
	PlayScene* getPlayScene();
	float timeTicks;
	std::vector<std::shared_ptr<ALLEGRO_BITMAP>> bmps;
	float timeSpan = 0.5;
public:
	ShootEffect(Engine::Point position);
	void Update(float deltaTime) override;
};
#endif // EXPLOSIONEFFECT_HPP
