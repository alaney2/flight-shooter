#pragma once

#include <cstdio>
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "common.h"
#include "player.h"
#include "projectile.h"
#include "enemy.h"

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
   * @return 
   */
  Player& GetPlayerAddress();
  
  /**
   * 
   */
  const void DisplayStartMenu() const;
  
  /**
   * 
   */
  const void DrawShapes() const;
  
  /**
   * 
   * @param position 
   */
  void SpawnProjectile(const ci::vec3 &position);
  
  void SpawnEnemy(const ci::vec3 &position);
  
  /**
   * 
   */
  void UpdateProjectiles();
  
  void UpdateEnemies();
  
  const size_t ProjectilesOnScreen() const;
  
  void StartGame();
  
  const bool OnStartMenu() const;
  
  const bool IsGameOver() const;
  
  void SetGameOver(bool game_over);
      
 private:
  bool on_start_menu_ = true;
  bool game_over_ = false;
  Player player_;
  std::vector<Projectile> projectiles_;
  std::vector<Enemy> enemies_;
};

}
