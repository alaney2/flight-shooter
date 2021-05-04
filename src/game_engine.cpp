#include "game_engine.h"

using ci::vec3;

namespace flightshooter {

GameEngine::GameEngine() {
  player_.SetPosition(ci::vec3(0));
}

const void GameEngine::Display() const {
  if (on_start_menu_) {
    DisplayStartMenu();
  } else if (on_instructions_page_) {
    DisplayInstructionsPage();
  } else {
    DrawShapes();
  }
}

void GameEngine::AdvanceOneFrame() {
  player_.UpdatePosition();
  UpdateProjectiles();
  UpdateEnemies();
}

Player& GameEngine::GetPlayerAddress() {
  return player_;
}

const void GameEngine::DisplayStartMenu() const {
  ci::gl::clear();

  ci::CameraPersp cam;
  cam.lookAt(vec3(0, 0, -360), vec3(360, 360, 0));
  ci::gl::setMatrices(cam);

  ci::gl::draw(
      ci::gl::Texture::create(loadImage(ci::app::loadAsset("space.jpg"))));

  ci::gl::drawStringCentered(("ɹǝʇooɥs ʇɥbıןɟ"),
                             glm::vec2(kWindowLength / 2, 3 * kWindowLength / 5),
                             "white", ci::Font("Times", 36));
  ci::gl::drawStringCentered(
      ("suoıʇɔnɹʇsuı ʍǝıʌ oʇ ǝ ssǝɹd"),
      glm::vec2(kWindowLength / 2,  kWindowLength / 2), "white",
      ci::Font("Times", 20));
  ci::gl::drawStringCentered(
      ("uıbǝq oʇ ɹɐqǝɔɐds"),
      glm::vec2(kWindowLength / 2, 2 * kWindowLength / 5), "white",
      ci::Font("Times", 20));
}

const void GameEngine::DisplayInstructionsPage() const {
  ci::gl::clear();

  ci::CameraPersp cam;
  cam.lookAt(vec3(0, 0, -360), vec3(360, 360, 0));
  ci::gl::setMatrices(cam);

  ci::gl::draw(
      ci::gl::Texture::create(loadImage(ci::app::loadAsset("space.jpg"))));

  ci::gl::drawStringCentered(
      ("suoıʇɔnɹʇsuı"), glm::vec2(kWindowLength / 2, 3 * kWindowLength / 5),
      "white", ci::Font("Times", 36));
  ci::gl::drawStringCentered(
      ("ǝʌoɯ oʇ p puɐ ɐ"),
      glm::vec2(kWindowLength / 2, 11 * kWindowLength / 20), "white",
      ci::Font("Times", 20));
  ci::gl::drawStringCentered(("ʇooɥs oʇ ʍ"),
                             glm::vec2(kWindowLength / 2, kWindowLength / 2),
                             "white", ci::Font("Times", 20));
  ci::gl::drawStringCentered(
      ("¡ǝɹoɔs ʇsǝɥbıɥ ǝɥʇ ɹoɟ ɯıɐ"),
      glm::vec2(kWindowLength / 2, 9 * kWindowLength / 20), "white",
      ci::Font("Times", 20));
}

const void GameEngine::DrawShapes() const {
  // Draw player
  ci::gl::clear(ci::Color(0.38f, 0.38f, 0.38f));  // gray background
  ci::gl::enableDepthRead();
  ci::gl::enableDepthWrite();

  ci::CameraPersp cam;
  cam.lookAt(vec3(0, 0, 4), vec3(0));
  ci::gl::setMatrices(cam);

  auto lambert = ci::gl::ShaderDef().lambert();
  auto shader = ci::gl::getStockShader(lambert);
  shader->bind();

  ci::gl::translate(0, -0.9, 0);
  ci::gl::drawCube(player_.GetPosition(), player_.GetScale());

  // Draw projectiles
  for (const Projectile& projectile : projectiles_) {
    ci::gl::pushModelMatrix();
    ci::gl::drawSphere(projectile.GetPosition(), projectile.GetRadius());
    ci::gl::popModelMatrix();
  }

  // Draw enemies
  for (const Enemy& enemy : enemies_) {
    ci::gl::pushModelMatrix();
    ci::gl::drawCube(enemy.GetPosition(), enemy.GetScale());
    ci::gl::popModelMatrix();
  }
}

void GameEngine::SpawnProjectile(const vec3& position) {
  Projectile projectile(position);
  projectiles_.emplace_back(projectile);
}

void GameEngine::SpawnEnemy(const vec3& position) {
  Enemy enemy(position);
  enemies_.emplace_back(enemy);
}

void GameEngine::UpdateProjectiles() {
  for (auto projectile = projectiles_.begin(); projectile != projectiles_.end();
       ++projectile) {
    projectile->MoveProjectileUp();

    if (projectile->GetPosition().y > kProjectileEraseThreshold) {
      projectiles_.erase(projectile);
      --projectile;
      break;
    }

    // Check collisions
    for (auto enemy = enemies_.begin(); enemy != enemies_.end(); ++enemy) {
      if (enemy->GetPosition().y - kCenterToBottom <=
          projectile->GetPosition().y) {
        if (enemy->GetPosition().x - kCenterToSide <=
                projectile->GetPosition().x &&
            enemy->GetPosition().x + kCenterToSide >=
                projectile->GetPosition().x) {
          enemies_.erase(enemy);
          projectiles_.erase(projectile);
          --enemy;
          --projectile;
        }
      }
    }
  }
}

void GameEngine::UpdateEnemies() {
  for (auto& enemy : enemies_) {
    enemy.MoveEnemyDown(enemy.GetSpeed() +
                        speed_counter_ * kSpeedIncreaseConstant);

    if (enemy.GetPosition().y < kEnemyEraseThreshold) {
      game_over_ = true;
      break;
    }
  }
}

void GameEngine::IncreaseSpeedCounter() {
  speed_counter_ += 1;
}

void GameEngine::ResetGame() {
  on_start_menu_ = false;
  on_instructions_page_ = false;
  speed_counter_ = 0;
  enemies_.clear();
  projectiles_.clear();
  player_.SetSpeed(static_cast<float>(kResetSpeed));
  player_.SetPosition(ci::vec3(0));
}

const size_t GameEngine::ProjectilesOnScreen() const {
  return projectiles_.size();
}

const bool GameEngine::IsGameOver() const {
  return game_over_;
}

const bool GameEngine::OnStartMenu() const {
  return on_start_menu_;
}

const double GameEngine::GetSpeedCounter() const {
  return speed_counter_;
}

const double GameEngine::GetIncreaseSpeedConstant() const {
  return kSpeedIncreaseConstant;
}

const std::vector<Projectile> GameEngine::GetProjectiles() const {
  return projectiles_;
}

const std::vector<Enemy> GameEngine::GetEnemies() const {
  return enemies_;
}

const bool GameEngine::GetInstructionsPage() const {
  return on_instructions_page_;
}

void GameEngine::SetGameOver(bool game_over) {
  game_over_ = game_over;
}

void GameEngine::SetStartMenu(bool start_menu) {
  on_start_menu_ = start_menu;
}

void GameEngine::SetInstructionsPage(bool instructions) {
  on_instructions_page_ = instructions;
}

}  // namespace flightshooter
