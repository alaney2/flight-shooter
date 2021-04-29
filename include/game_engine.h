#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "player.h"
#include "projectile.h"

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
  
  /**
   * 
   */
  void UpdateProjectiles();
  
  const size_t ProjectilesOnScreen() const;
  
 private:
  Player player_;
  std::vector<Projectile> projectiles_;
};

}
