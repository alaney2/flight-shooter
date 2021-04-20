#include "flight_shooter_app.h"

namespace flightshooter {

TPShooterApp::TPShooterApp() {
  ci::app::setWindowSize(kWindowWidth_, kWindowLength_);
}

void TPShooterApp::draw() {
  ci::Color background_color("black");
  ci::gl::clear(background_color);
  
  engine.Display();
}

void TPShooterApp::update() {
  engine.AdvanceOneFrame();
}

void TPShooterApp::keyDown(cinder::app::KeyEvent event) {
  AppBase::keyDown(event);
}

} // namespace tpshooter