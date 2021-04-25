#pragma once

#include "player.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

namespace flightshooter {

class GameEngine {
 public:
  GameEngine();
  
  const void Display() const;
  
  void AdvanceOneFrame();
  
  const void DrawPlayer() const;

  Player& GetPlayerAddress();

 private:
  Player player_;

};

}
