#include <string>

#include "Boss.hpp"
#include "PlayScene.hpp"
#include "DiceEnemy.hpp"
#include "TankEnemy.hpp"

BossEnemy::BossEnemy(int x, int y) : Enemy("play/enemy-2.png", x, y, 25, 25, 35, 50) {
    // TODO 2 (1/3): You can imitate the 2 files: 'RedNormalEnemy.hpp', 'RedNormalEnemy.cpp' to create a new enemy.
}
void BossEnemy::Update(float deltaTime)
{
	// Slow effect.
	SlowEffect(deltaTime);
	// Pre-calculate the velocity.
	float remainSpeed = speed * deltaTime;
	while (remainSpeed != 0) {
		if (path.empty()) {
			// Reach end point.
			Hit(hp);
			getPlayScene()->Hit();
			reachEndTime = 0;
			return;
		}
		Engine::Point target = path.back() * PlayScene::BlockSize + Engine::Point(PlayScene::BlockSize / 2, PlayScene::BlockSize / 2);
		Engine::Point vec = target - Position;
		// Add up the distances:
		// 1. to path.back()
		// 2. path.back() to border
		// 3. All intermediate block size
		// 4. to end point
		reachEndTime = (vec.Magnitude() + (path.size() - 1) * PlayScene::BlockSize - remainSpeed) / speed;
		Engine::Point normalized = vec.Normalize();
		if (remainSpeed - vec.Magnitude() > 0) {
			Position = target;
			path.pop_back();
			remainSpeed -= vec.Magnitude();
		}
		else {
			Velocity = normalized * remainSpeed / deltaTime;
			remainSpeed = 0;
		}
	}
	this->count -= deltaTime;
	if (this->count <= 0)
	{
		this->count = this->spawn;
		Enemy* enemy;
		int random = rand() % 2;
		if (random == 0) getPlayScene()->EnemyGroup->AddNewObject(enemy = new DiceEnemy(Position.x, Position.y));
		else getPlayScene()->EnemyGroup->AddNewObject(enemy = new TankEnemy(Position.x, Position.y));
		enemy->UpdatePath(getPlayScene()->mapDistance);

	}
	Rotation = atan2(Velocity.y, Velocity.x);
	Sprite::Update(deltaTime);
}
