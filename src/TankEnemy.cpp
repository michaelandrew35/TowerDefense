#include <string>
#include <random>

#include "TankEnemy.hpp"
#include "AudioHelper.hpp"
#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "ExplosionEffect.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "DiceEnemy.hpp"
using namespace Engine;
TankEnemy::TankEnemy(int x, int y) : Enemy("play/dice-2.png", x, y, 25, 50, 10, 15) {
	// TODO 2 (1/3): You can imitate the 2 files: 'RedNormalEnemy.hpp', 'RedNormalEnemy.cpp' to create a new enemy.
}
void TankEnemy::OnExplode() {
	getPlayScene()->EffectGroup->AddNewObject(new ExplosionEffect(Position.x, Position.y));
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distId(1, 3);
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 20);
	for (int i = 0; i < 10; i++) {
		// Random add 10 dirty effects.
		getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-" + std::to_string(distId(rng)) + ".png", dist(rng), Position.x, Position.y));
	}
	Enemy* spawn;
	getPlayScene()->EnemyGroup->AddNewObject(spawn = new DiceEnemy(Position.x, Position.y));
	spawn->UpdatePath(getPlayScene()->mapDistance);
}