#include "flight_shooter_app.h"

namespace flightshooter {

FlightShooter::FlightShooter() {
  ci::app::setWindowSize(kWindowWidth_, kWindowLength_);
}

void FlightShooter::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  engine_.Display();
  ci::gl::drawStringCentered(std::to_string(score_), glm::vec2(0, 0));
}

void FlightShooter::update() {
  if (score_ % 40 == 0) {
    double f = static_cast<double>(rand()) / RAND_MAX;
    double x_pos = -kBoundary_ + f * (2 * kBoundary_);
    ci::vec3 enemy_pos(x_pos, 2, 0);
    engine_.SpawnEnemy(enemy_pos);
  }
  engine_.AdvanceOneFrame();
  ++score_;
}

void FlightShooter::keyDown(cinder::app::KeyEvent event) {
  if (event.getCode() == cinder::app::KeyEvent::KEY_a
      || event.getCode() == cinder::app::KeyEvent::KEY_d) {
    engine_.GetPlayerAddress().ToggleMovement(true);
    engine_.GetPlayerAddress().SetMovementDirection(event.getChar());
  }
  
  if (event.getCode() == cinder::app::KeyEvent::KEY_w) {
    if (engine_.ProjectilesOnScreen() < kMaxProjectiles_) {
      engine_.SpawnProjectile(engine_.GetPlayerAddress().GetPosition());
    }
  }
}

void FlightShooter::keyUp(cinder::app::KeyEvent event) {
  if (event.getCode() == cinder::app::KeyEvent::KEY_a 
    || event.getCode() == cinder::app::KeyEvent::KEY_d) {
    engine_.GetPlayerAddress().ToggleMovement(false);
  }
}

} // namespace flightshooter