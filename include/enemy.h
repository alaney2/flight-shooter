#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

namespace flightshooter {

class Enemy {
 public:
  Enemy(const ci::vec3 &position);
  void MoveEnemyDown(double speed);
  const ci::vec3 GetPosition() const;
  const ci::vec3 GetScale() const;
  const double GetSpeed() const;
  
 private:
  // Nothing can be const here in order to use erase on a vector of Enemies
  ci::vec3 position_;
  double kEnemySpeed_ = 0.02;
  ci::vec3 kScale_ = ci::vec3(0.4, 0.3, 0.3);
};
}
