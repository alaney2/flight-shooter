#include "flight_shooter_app.h"

namespace flightshooter {

FlightShooter::FlightShooter() {
  ci::app::setWindowSize(kWindowWidth_, kWindowLength_);
}

void FlightShooter::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);

  engine_.Display();
}

void FlightShooter::update() {
  engine_.AdvanceOneFrame();
}

void FlightShooter::keyDown(cinder::app::KeyEvent event) {
  if (event.getCode() == cinder::app::KeyEvent::KEY_a
      || event.getCode() == cinder::app::KeyEvent::KEY_d) {
    engine_.GetPlayerAddress().ToggleMovement(true);
    engine_.GetPlayerAddress().SetMovementDirection(event.getChar());
  }
  
  if (event.getCode() == cinder::app::KeyEvent::KEY_w) {
    engine_.SpawnProjectile(engine_.GetPlayerAddress().GetPosition());
  }
}

void FlightShooter::keyUp(cinder::app::KeyEvent event) {
  if (event.getCode() == cinder::app::KeyEvent::KEY_a 
    || event.getCode() == cinder::app::KeyEvent::KEY_d) {
    engine_.GetPlayerAddress().ToggleMovement(false);
  }
}

} // namespace flightshooter