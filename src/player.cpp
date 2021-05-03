#include "player.h"

namespace flightshooter {

const ci::vec3 Player::GetScale() const {
  return kScale;
}

void Player::Strafe(char direction) {
  if (direction == 'a') {
    position_.x -= player_speed_;
  }

  if (direction == 'd') {
    position_.x += player_speed_;
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
  if (position_.x >= kBoundary) {
    position_.x = static_cast<float>(kBoundary);
  } else if (position_.x <= -kBoundary) {
    position_.x = static_cast<float>(-kBoundary);
  }
}

void Player::SetMovingLeft(bool left) {
  moving_left_ = left;
}

void Player::SetMovingRight(bool right) {
  moving_right_ = right;
}

const float Player::GetSpeed() const {
  return player_speed_;
}

void Player::SetSpeed(float speed) {
  player_speed_ = speed;
}

}  // namespace flightshooter