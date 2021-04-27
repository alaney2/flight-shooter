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

}