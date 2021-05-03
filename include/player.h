#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "common.h"

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
   */
  void UpdatePosition();

  const ci::vec3 GetScale() const;
  const ci::vec3 GetPosition() const;
  void SetPosition(const ci::vec3 &position);
  void SetMovingLeft(bool left);

  void SetMovingRight(bool right);
  
  
 private:
  bool moving_left_ = false;
  bool moving_right_ = false;
  ci::vec3 position_;
  const ci::vec3 kScale_ = ci::vec3(0.5, 0.4, 0.4);
  const float kPlayerSpeed_ = 0.05;
};

}