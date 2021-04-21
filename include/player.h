#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

namespace flightshooter {

class Player {
 public:
  const ci::vec3 GetScale() const;
  void Strafe(char direction);
  
 private:
  ci::vec3 position_ = ci::vec3(0);
  const ci::vec3 kScale_ = ci::vec3(0.5, 0.3, 0.3);
  const size_t kSpeed_ = 5;
};

}