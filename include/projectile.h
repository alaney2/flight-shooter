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
  
 private:
  const double kProjectileSpeed_ = 0.1;
  ci::vec3 position_;
};
}
