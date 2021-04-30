#include "enemy.h"

namespace flightshooter {

Enemy::Enemy(const glm::vec3& position) : position_(position) {
}

void Enemy::MoveEnemyDown() {
  position_.y -= static_cast<float>(kEnemySpeed_);
}

const ci::vec3 Enemy::GetPosition() const {
  return position_;
}

const ci::vec3 Enemy::GetScale() const {
  return kScale_;
}
}
