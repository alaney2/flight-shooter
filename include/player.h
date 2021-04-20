#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

namespace flightshooter {

class Player {
 public:
  const ci::vec3 GetScale() const;
  
 private:
  ci::vec3 position_ = ci::vec3();
  const ci::vec3 scale_ = ci::vec3(0.5, 0.3, 0.3);
};

}