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

  Player ModifyPlayer() const;
  
 private:
  Player player_;
};

}
