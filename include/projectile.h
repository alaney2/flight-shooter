#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace flightshooter {
class Projectile {
 public:
  /**
   * Constructor that initializes projectiles.
   *
   * @param position
   */
  Projectile(const ci::vec3 &position);

  /**
   * Method that moves the projectiles up.
   */
  void MoveProjectileUp();

  // Getter methods
  const ci::vec3 GetPosition() const;
  const float GetRadius() const;

 private:
  // Nothing can be const here in order to use erase on a vector of Projectiles

  double projectile_speed_ = 0.06;  // speed that projectiles move in
  ci::vec3 position_;               // position of projectiles
  float kRadius_ = 0.1;             // radius of projectiles
};
}  // namespace flightshooter
