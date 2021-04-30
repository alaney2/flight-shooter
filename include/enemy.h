#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

namespace flightshooter {

class Enemy {
 public:
  Enemy(const ci::vec3 &position);
  void MoveEnemyDown();
  
 private:
  ci::vec3 position_;
  const double kEnemySpeed_ = 0.04;
};
}
