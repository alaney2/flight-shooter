#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "common.h"
#include "game_engine.h"

namespace flightshooter {

class FlightShooter : public ci::app::App {
 public:
  /**
   * Constructor that initializes game, sets game frame.
   */
  FlightShooter();

  /**
   * Method that shows current game state.
   */
  void draw() override;

  /**
   * Method that updates current game state.
   */
  void update() override;

  /**
   * Method that determines and executes actions after key is pressed.
   *
   * @param event key pressed
   */
  void keyDown(cinder::app::KeyEvent event) override;

  /**
   * Method that determines and executes actions after key is released.
   *
   * @param event key released
   */
  void keyUp(cinder::app::KeyEvent event) override;

  /**
   * Method that displays the game over menu.
   */
  const void DisplayGameOverMenu() const;

 private:
  const size_t kMaxProjectiles =
      5;  // maximum number of projectiles player can shoot

  const size_t kAccelerationDistance =
      500;  // distance that triggers acceleration
  const size_t kEnemyGeneratingFactor = 40;  // factor that enemy generates by
  const size_t kEnemyGeneratingScore = 100;  // score that enemy generates by

  GameEngine engine_;      // instance of game engine
  size_t score_ = 0;       // player current score
  size_t high_score_ = 0;  // player record score
};

}  // namespace flightshooter
