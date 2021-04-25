#include "player.h"

namespace flightshooter {

const ci::vec3 Player::GetScale() const {
  return kScale_;
}

void Player::Strafe(char direction) {
  if (direction == 'a') {
    position_.x -= kSpeed_;
  }
  
  if (direction == 'd') {
    position_.x += kSpeed_;
  }
}

const ci::vec3 Player::GetPosition() const {
  return position_;
}

void Player::SetPosition(const ci::vec3 &position) {
  position_ = position;
}

void Player::ToggleMovement(bool is_moving) {
  moving_ = is_moving;
}

bool Player::isPlayerMoving() {
  return moving_;
}

void Player::SetMovementDirection(char direction) {
  movement_direction_ = direction;
}

void Player::UpdatePosition() {
  if (moving_) {
    Strafe(movement_direction_);
  }
}

}