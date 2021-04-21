#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

namespace flightshooter {

class Player {
 public:
  const ci::vec3 GetScale() const;
  void Strafe(char direction);
  const ci::vec3 GetPosition() const;
  void SetPosition(const ci::vec3 &position);
  
 private:
  ci::vec3 position_;
  const ci::vec3 kScale_ = ci::vec3(0.5, 0.3, 0.3);
  const float kSpeed_ = 0.15;
};

}