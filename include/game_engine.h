#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "player.h"
#import "projectile.h"

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
  const void DrawShapes() const;

  /**
   * 
   * @param position 
   */
  void SpawnProjectile(const ci::vec3 &position);
  
 private:
  Player player_;
  std::vector<Projectile> projectiles_;
};

}
