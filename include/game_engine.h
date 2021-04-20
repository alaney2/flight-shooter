#pragma once

#include "player.h"
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
  Player player_;
};

}
