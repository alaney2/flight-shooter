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
  if (event.getCode() == cinder::app::KeyEvent::KEY_d
      || event.getCode() == cinder::app::KeyEvent::KEY_a) {
    engine_.GetPlayerAddress()->Strafe(event.getChar());
//    std::cout << event.getChar() << std::endl;
  }
  
  if (event.getCode() == cinder::app::KeyEvent::KEY_w) {
    // shoot projectile
  }
}

} // namespace flightshooter