#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"

namespace flightshooter {

class Player {
 public:
  /**
   * 
   * @param direction 
   */
  void Strafe(char direction);
  
  /**
   * 
   * @param is_moving 
   */
  void ToggleMovement(bool is_moving);
  
  /**
   * 
   * @param direction 
   */
  void SetMovementDirection(char direction);

  /**
   * 
   */
  void UpdatePosition();

  const ci::vec3 GetScale() const;
  const ci::vec3 GetPosition() const;
  void SetPosition(const ci::vec3 &position);
  bool isPlayerMoving();
  
 private:
  bool moving_ = false;
  char movement_direction_;
  ci::vec3 position_;
  const ci::vec3 kScale_ = ci::vec3(0.5, 0.3, 0.3);
  const float kSpeed_ = 0.05;
  const double kBoundary_ = 1.3;
};

}