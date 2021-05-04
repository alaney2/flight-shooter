#pragma once

#include <cstdio>

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "common.h"
#include "enemy.h"
#include "player.h"
#include "projectile.h"

namespace flightshooter {

class GameEngine {
 public:
  GameEngine();

  /**
   * Method that displays the game frame.
   */
  const void Display() const;

  /**
   * Method that gets called on every frame to update game.
   */
  void AdvanceOneFrame();

  /**
   * Method that gets the player's address.
   *
   * @return player address as an instance of player
   */
  Player &GetPlayerAddress();

  /**
   * Method that displays the starting menu.
   */
  const void DisplayStartMenu() const;

  /**
   * Method that draws the shapes in game.
   */
  const void DrawShapes() const;

  /**
   * Method that spawns projectiles in game.
   *
   * @param position
   */
  void SpawnProjectile(const ci::vec3 &position);

  /**
   * Method that spawns enemies in game.
   *
   * @param position
   */
  void SpawnEnemy(const ci::vec3 &position);

  /**
   * Method that updates projectiles' motions.
   */
  void UpdateProjectiles();

  /**
   * Method that updates enemies' motions.
   */
  void UpdateEnemies();

  /**
   * Method that increases the count for speed to increase speed accordingly.
   */
  void IncreaseSpeedCounter();

  /**
   * Method that returns the number of projectiles on screen.
   *
   * @return number of projecties on screen
   */
  const size_t ProjectilesOnScreen() const;

  /**
   *
   */
  void ResetGame();

  /**
   * Returns whether player is on start menu.
   *
   * @return true if on menu false otherwise
   */
  const bool OnStartMenu() const;

  /**
   * Returns whether game is over.
   *
   * @return true if over false otherwise
   */
  const bool IsGameOver() const;

  // Getter methods
  const double GetSpeedCounter() const;
  const double GetIncreaseSpeedConstant() const;
  const std::vector<Projectile> GetProjectiles() const;
  const std::vector<Enemy> GetEnemies() const;
  
  // Setter methods
  void SetGameOver(bool game_over);
  void SetStartMenu(bool start_menu);

 private:
  const double kSpeedIncreaseConstant = 0.005;   // constant speed increases by
  const double kResetSpeed = 0.045;              // speed to reset to
  const float kEnemyEraseThreshold = -1.0f;      // erase threshold
  const float kProjectileEraseThreshold = 3.0f;  // projectile erase threshold
  const double kCenterToBottom =
      0.2;                           // distance from center of enemy to bottom
  const double kCenterToSide = 0.3;  // distance from center of enemy to side

  double speed_counter_ = 0;   // counter for acceleration purpose
  bool on_start_menu_ = true;  // boolean that determines whether on start menu
  bool game_over_ = false;     // boolean that determines whether game is over

  Player player_;                        // instance of player
  std::vector<Projectile> projectiles_;  // vector of projectiles
  std::vector<Enemy> enemies_;           // vector of enemies
};

}  // namespace flightshooter
