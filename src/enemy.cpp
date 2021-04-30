#include "enemy.h"

namespace flightshooter {

Enemy::Enemy(const glm::vec3& position) : position_(position) {
}

void Enemy::MoveEnemyDown() {
  position_.y -= static_cast<float>(kEnemySpeed_);
}
}
