#include "flight_shooter_app.h"

namespace flightshooter {

FlightShooter::FlightShooter() {
  ci::app::setWindowSize(kWindowWidth, kWindowLength);
}

void FlightShooter::draw() {
  if (!engine_.IsGameOver()) {
    engine_.Display();
  } else {
    high_score_ = std::max(score_, high_score_);
    DisplayGameOverMenu();
  }
}

void FlightShooter::update() {
  if (!engine_.IsGameOver() && !engine_.OnStartMenu()) {
    // Spawn enemies
    if (score_ % kEnemyGeneratingFactor == 0 &&
        score_ > kEnemyGeneratingScore) {
      double f = static_cast<double>(rand()) / RAND_MAX;
      double x_pos = -kBoundary + f * (2 * kBoundary);
      ci::vec3 enemy_pos(x_pos, 2, 0);
      engine_.SpawnEnemy(enemy_pos);
    }
    
    // Increase enemy and player speeds
    if (score_ % kAccelerationDistance == 0) {
      engine_.IncreaseSpeedCounter();
      engine_.GetPlayerAddress().SetSpeed(static_cast<float>(
          engine_.GetPlayerAddress().GetSpeed() +
          engine_.GetSpeedCounter() * engine_.GetIncreaseSpeedConstant()));
    }
    
    engine_.AdvanceOneFrame();
    ++score_;
  }
}

void FlightShooter::keyDown(cinder::app::KeyEvent event) {
  // Move player
  if (event.getCode() == cinder::app::KeyEvent::KEY_a) {
    engine_.GetPlayerAddress().SetMovingLeft(true);
  }

  if (event.getCode() == cinder::app::KeyEvent::KEY_d) {
    engine_.GetPlayerAddress().SetMovingRight(true);
  }

  // Shoot projectile
  if (event.getCode() == cinder::app::KeyEvent::KEY_w) {
    if (engine_.ProjectilesOnScreen() < kMaxProjectiles) {
      engine_.SpawnProjectile(engine_.GetPlayerAddress().GetPosition());
    }
  }

  // Start game
  if (event.getCode() == cinder::app::KeyEvent::KEY_SPACE && engine_.OnStartMenu()) {
    engine_.SetStartMenu(false);
  }
  
  // View instructions
  if (event.getCode() == cinder::app::KeyEvent::KEY_e) {
    engine_.SetInstructionsPage(!engine_.GetInstructionsPage());
    engine_.SetStartMenu(!engine_.OnStartMenu());
  }

  // Restart game
  if (event.getCode() == cinder::app::KeyEvent::KEY_r && engine_.IsGameOver()) {
    score_ = 0;
    engine_.SetGameOver(false);
    engine_.ResetGame();
  }
}

void FlightShooter::keyUp(cinder::app::KeyEvent event) {
  if (event.getCode() == cinder::app::KeyEvent::KEY_a) {
    engine_.GetPlayerAddress().SetMovingLeft(false);
  }

  if (event.getCode() == cinder::app::KeyEvent::KEY_d) {
    engine_.GetPlayerAddress().SetMovingRight(false);
  }
}

const void FlightShooter::DisplayGameOverMenu() const {
  ci::gl::clear();

  ci::CameraPersp cam;
  cam.lookAt(ci::vec3(0, 0, -360), ci::vec3(360, 360, 0));
  ci::gl::setMatrices(cam);

  ci::gl::drawStringCentered(
      ("??????o??????b"), glm::vec2(kWindowLength / 2, 2 * kWindowLength / 3),
      "white", ci::Font("Times", 32));
  ci::gl::drawStringCentered(std::to_string(score_) + " :????o??s",
                             glm::vec2(kWindowLength / 2, 3 * kWindowLength / 5),
                             "white", ci::Font("Times", 32));
  ci::gl::drawStringCentered(
      std::to_string(high_score_) + " :????o??s ??b????",
      glm::vec2(kWindowLength / 2, 11 * kWindowLength / 20), "white",
      ci::Font("Times", 32));
  ci::gl::drawStringCentered(" (??u??op ??p??sdn ????o??s ?????? p??????)",
      glm::vec2(kWindowLength / 2, kWindowLength / 2), "white",
      ci::Font("Times", 32));
  ci::gl::drawStringCentered(
      ("u????b?? ??????d o?? ,??, ss????d"),
      glm::vec2(kWindowLength / 2, 2 * kWindowLength / 5), "white",
      ci::Font("Times", 32));
}

}  // namespace flightshooter