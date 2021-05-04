#include "enemy.h"

namespace flightshooter {

Enemy::Enemy(const glm::vec3& position) : position_(position) {
}

void Enemy::MoveEnemyDown(double speed) {
  position_.y -= static_cast<float>(speed);
}

const ci::vec3 Enemy::GetPosition() const {
  return position_;
}

const ci::vec3 Enemy::GetScale() const {
  return scale_;
}

const double Enemy::GetSpeed() const {
  return enemy_speed_;
}

}  // namespace flightshooter
