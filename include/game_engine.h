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

  // Setter methods
  void SetGameOver(bool game_over);
  void SetStartMenu(bool start_menu);

 private:
  const double kSpeedIncreaseConstant = 0.005;  // constant speed increases by

  double speed_counter_ = 0;   // counter for acceleration purpose
  bool on_start_menu_ = true;  // boolean that determines whether on start menu
  bool game_over_ = false;     // boolean that determines whether game is over

  Player player_;                        // instance of player
  std::vector<Projectile> projectiles_;  // vector of projectiles
  std::vector<Enemy> enemies_;           // vector of enemies
};

}  // namespace flightshooter
