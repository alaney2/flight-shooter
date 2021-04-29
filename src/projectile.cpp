#include "projectile.h"

namespace flightshooter {

Projectile::Projectile(const ci::vec3 &position) : position_(position) { }

void Projectile::MoveProjectileUp() {
  position_.y += static_cast<float>(kProjectileSpeed_);
}

const ci::vec3 Projectile::GetPosition() const {
  return position_;
}

}