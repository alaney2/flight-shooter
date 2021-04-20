#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

namespace flightshooter {

class GameEngine {
 public:
  GameEngine();
  
  void Display() const;
  
  void AdvanceOneFrame();
  
  void StrafeDirection(char direction);
  
 private:
  ci::vec3 position_ = ci::vec3();
};

}
