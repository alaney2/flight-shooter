#include "player.h"

namespace flightshooter {

const ci::vec3 Player::GetScale() const {
  return kScale_;
}

void Player::Strafe(char direction) {
  if (direction == 'a') {
    position_.x -= kPlayerSpeed_;
  }
  
  if (direction == 'd') {
    position_.x += kPlayerSpeed_;
  }
}

const ci::vec3 Player::GetPosition() const {
  return position_;
}

void Player::SetPosition(const ci::vec3 &position) {
  position_ = position;
}

void Player::UpdatePosition() {
  if (moving_left_) {
    Strafe('a');
  }
  if (moving_right_) {
    Strafe('d');
  }
  if (position_.x >= kBoundary_) {
    position_.x = static_cast<float>(kBoundary_);
  } else if (position_.x <= -kBoundary_) {
    position_.x = static_cast<float>(-kBoundary_);
  }
}

void Player::SetMovingLeft(bool left) {
  moving_left_ = left;
}

void Player::SetMovingRight(bool right) {
  moving_right_ = right;
}

}