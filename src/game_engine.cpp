#include "game_engine.h"

using ci::vec3;

namespace flightshooter {

GameEngine::GameEngine() {
  player_.SetPosition(ci::vec3(0));
}

const void GameEngine::Display() const {
  if (on_start_menu_) {
    DisplayStartMenu();
  } else {
    DrawShapes();
  }
//  ci::gl::draw(ci::gl::Texture::create(loadImage(ci::app::loadAsset("space.jpg"))));
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
  ci::gl::draw(ci::gl::Texture::create(loadImage(ci::app::loadAsset("space.jpg"))));

  ci::gl::drawStringCentered(("Flight Shooter"), glm::vec2(kWindowLength_/2, 2*kWindowLength_/5), "white", ci::Font("Helvetica", 32));

  ci::gl::drawStringCentered(("Press spacebar to begin"), glm::vec2(kWindowLength_/2, 2*kWindowLength_/3), "white", ci::Font("Helvetica", 20));

}

const void GameEngine::DrawShapes() const {
  // Draw player
  ci::gl::clear(ci::Color( 0.5f, 0.5f, 0.5f ));

  ci::gl::enableDepthRead();
  ci::gl::enableDepthWrite();

  ci::CameraPersp cam;
  cam.lookAt( vec3( 0, 0, 4), vec3( 0,0,0));
  ci::gl::setMatrices(cam);

  auto lambert = ci::gl::ShaderDef().lambert();
  auto shader = ci::gl::getStockShader(lambert);
  shader->bind();
  
  ci::gl::translate(0, -0.8, 0);
  ci::gl::drawCube( player_.GetPosition(), player_.GetScale());
  
  // Draw projectiles
  for (const Projectile& projectile: projectiles_) {
    ci::gl::pushModelMatrix();

//    ci::gl::scale(projectile.GetScale());
    ci::gl::drawSphere(projectile.GetPosition(), projectile.GetRadius());

    ci::gl::popModelMatrix();
  }
  
  //Draw enemies
  for (const Enemy& enemy: enemies_) {
    ci::gl::pushModelMatrix();

    ci::gl::drawCube(enemy.GetPosition(), enemy.GetScale());
    ci::gl::popModelMatrix();
  }
}

const void GameEngine::DisplayGameOver() const {
  
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
  for (auto projectile = projectiles_.begin(); projectile != projectiles_.end(); ++projectile) {
    projectile->MoveProjectileUp();
    
    float erase_threshold = 3.0f;
    if (projectile->GetPosition().y > erase_threshold) {
      projectiles_.erase(projectile);
      --projectile;
    }
    
    // Check collisions
    for (auto enemy = enemies_.begin(); enemy != enemies_.end(); ++enemy) {
      if (enemy->GetPosition().y - 0.2 <= projectile->GetPosition().y) {
        if (enemy->GetPosition().x - 0.3 <= projectile->GetPosition().x
            && enemy->GetPosition().x + 0.3 >= projectile->GetPosition().x) {
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
  for (auto enemy = enemies_.begin(); enemy != enemies_.end(); ++enemy) {
    enemy->MoveEnemyDown();

    float erase_threshold = -3.0f;
    if (enemy->GetPosition().y < erase_threshold) {
      game_over_ = true;
      enemies_.erase(enemy);
      --enemy;
    }
  }
}

const size_t GameEngine::ProjectilesOnScreen() const {
  return projectiles_.size();
}

void GameEngine::StartGame() {
  on_start_menu_ = false;
}



const bool GameEngine::IsGameOver() const {
  return game_over_;
}

void GameEngine::SetGameOver(bool game_over) {
  game_over_ = game_over;
}

const bool GameEngine::OnStartMenu() const {
  return on_start_menu_;
}

}
