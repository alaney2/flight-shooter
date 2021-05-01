#include "flight_shooter_app.h"

namespace flightshooter {

FlightShooter::FlightShooter() {
  ci::app::setWindowSize(kWindowWidth_, kWindowLength_);
}

void FlightShooter::draw() {
  if (!engine_.IsGameOver()) {
    engine_.Display();
  } else {
    DisplayGameOverMenu();
  }
}

void FlightShooter::update() {
  if (!engine_.IsGameOver() && !engine_.OnStartMenu()) {
    if (score_ % 40 == 0 && score_ >= 200) {
      double f = static_cast<double>(rand()) / RAND_MAX;
      double x_pos = -kBoundary_ + f * (2 * kBoundary_);
      ci::vec3 enemy_pos(x_pos, 2, 0);
      engine_.SpawnEnemy(enemy_pos);
    }
    engine_.AdvanceOneFrame();
    ++score_;
  }
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
  
  if (event.getCode() == cinder::app::KeyEvent::KEY_SPACE) {
    engine_.StartGame();
  }
  
  if (event.getCode() == cinder::app::KeyEvent::KEY_r) {
    engine_.SetGameOver(false);
  }
}

void FlightShooter::keyUp(cinder::app::KeyEvent event) {
  if (event.getCode() == cinder::app::KeyEvent::KEY_a 
    || event.getCode() == cinder::app::KeyEvent::KEY_d) {
    engine_.GetPlayerAddress().ToggleMovement(false);
  }
}
const void FlightShooter::DisplayGameOverMenu() const {
  ci::gl::drawStringCentered(("GAMEOVER"), glm::vec2(kWindowLength_/2, 2*kWindowLength_/5), "white", ci::Font("Helvetica", 32));
  ci::gl::drawStringCentered(("Press 'R' to play again"), glm::vec2(kWindowLength_/2, 2*kWindowLength_/5), "white", ci::Font("Helvetica", 32));

}

} // namespace flightshooter