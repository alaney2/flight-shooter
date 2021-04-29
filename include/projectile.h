#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

namespace flightshooter {
class Projectile {
 public:
  Projectile(const ci::vec3 &position);
  
 private:
  ci::vec3 position_;
};
}
