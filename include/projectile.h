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
  const ci::vec3 GetScale() const;
  const float GetRadius() const;
  
 private:
  const double kProjectileSpeed_ = 0.1;
  ci::vec3 position_;
  ci::vec3 kScale_ = ci::vec3(0.45, 0.3, 0.3);
  const float kRadius_ = 0.1;
};
}
