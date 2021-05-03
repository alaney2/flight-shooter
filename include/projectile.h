#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

namespace flightshooter {
class Projectile {
 public:
  Projectile(const ci::vec3 &position);
  void MoveProjectileUp();
  const ci::vec3 GetPosition() const;
  const float GetRadius() const;
  
 private:
  // Nothing can be const here in order to use erase on a vector of Projectiles
  double projectile_speed_ = 0.06;
  ci::vec3 position_;
  float kRadius_ = 0.1;
};
}
