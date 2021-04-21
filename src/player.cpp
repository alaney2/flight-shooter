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

}