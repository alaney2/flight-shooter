#include "flight_shooter_app.h"

namespace flightshooter {

FlightShooter::FlightShooter() {
  ci::app::setWindowSize(kWindowWidth_, kWindowLength_);
}

void FlightShooter::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
  
  engine.Display();
}

void FlightShooter::update() {
  engine.AdvanceOneFrame();
}

void FlightShooter::keyDown(cinder::app::KeyEvent event) {
  if (event.getCode() == cinder::app::KeyEvent::KEY_w
      || event.getCode() == cinder::app::KeyEvent::KEY_a) {
    engine.StrafeDirection(event.getChar());
  }
}

} // namespace flightshooter