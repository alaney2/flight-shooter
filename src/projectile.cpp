#include "projectile.h"

namespace flightshooter {

Projectile::Projectile(const ci::vec3 &position) : position_(position) { }

void Projectile::MoveProjectileUp() {
  position_.y += static_cast<float>(projectile_speed_);
}

const ci::vec3 Projectile::GetPosition() const {
  return position_;
}

const float Projectile::GetRadius() const {
  return kRadius_;
}

}