#pragma once

#include "player.h"
#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

namespace flightshooter {

class GameEngine {
 public:
  GameEngine();
  
  /**
   * 
   */
  const void Display() const;
  
  /**
   * 
   */
  void AdvanceOneFrame();
  
  /**
   * 
   */
  const void DrawPlayer() const;
  
  /**
   * 
   * @return 
   */
  Player& GetPlayerAddress();
  
  /**
   * 
   */
  const void ShootProjectile() const;
  
  /**
   * 
   */
  const void DrawShapes() const;
  
 private:
  Player player_;
  
};

}
