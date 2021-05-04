#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

namespace flightshooter {

class Enemy {
 public:
  /**
   * Constructor that initializes enemies.
   *
   * @param position
   */
  Enemy(const ci::vec3 &position);

  /**
   * Method that updates enemy position/moves it down.
   *
   * @param speed to move at
   */
  void MoveEnemyDown(double speed);

  // Getter methods
  const ci::vec3 GetPosition() const;
  const ci::vec3 GetScale() const;
  const double GetSpeed() const;

 private:
  // Nothing can be const here in order to use erase on a vector of Enemies

  double enemy_speed_ = 0.02;                 // speed enemies move at
  ci::vec3 position_;                         // vector of positions of enemy
  ci::vec3 scale_ = ci::vec3(0.4, 0.3, 0.3);  // how much enemies are scaled by
};

}  // namespace flightshooter
