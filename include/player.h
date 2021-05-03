#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "common.h"

namespace flightshooter {

class Player {
 public:
  /**
   * Method that moves the shooter by key.
   *
   * @param direction for player to move in
   */
  void Strafe(char direction);

  /**
   * Method that updates player position.
   */
  void UpdatePosition();

  // Getter methods
  const ci::vec3 GetScale() const;
  const ci::vec3 GetPosition() const;
  const float GetSpeed() const;
  
  // Setter methods
  void SetSpeed(float speed);
  void SetPosition(const ci::vec3 &position);
  void SetMovingLeft(bool left);
  void SetMovingRight(bool right);

 private:
  const ci::vec3 kScale =
      ci::vec3(0.5, 0.4, 0.4);       // how much player is scaled by
  float player_speed_ = 0.045;  // player move speed

  bool moving_left_ = false;   // determines whether player is moving left
  bool moving_right_ = false;  // determines whether player is moving right
  ci::vec3 position_;          // position of player as vec3
};

}  // namespace flightshooter