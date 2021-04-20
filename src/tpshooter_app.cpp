#include "tpshooter_app.h"

namespace tpshooter {

TPShooterApp::TPShooterApp() {
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