#include "game_engine.h"

using ci::vec3;

namespace flightshooter {

GameEngine::GameEngine() {
  player_.SetPosition(ci::vec3(0));
}

const void GameEngine::Display() const {
//  DrawPlayer();
  DrawShapes();
}

void GameEngine::AdvanceOneFrame() {
  player_.UpdatePosition();
  UpdateProjectiles();
}

Player& GameEngine::GetPlayerAddress() {
  return player_;
}

const void GameEngine::DrawPlayer() const {
  ci::gl::clear();
  ci::gl::enableDepthRead();
  ci::gl::enableDepthWrite();

  ci::CameraPersp cam;
  cam.lookAt( vec3( 0, 3, 3 ), vec3( 0,1,0));
  ci::gl::setMatrices(cam);

  auto lambert = ci::gl::ShaderDef().lambert();
  auto shader = ci::gl::getStockShader(lambert);
  shader->bind();

  ci::gl::drawCube( player_.GetPosition(), player_.GetScale());
}

//const void GameEngine::ShootProjectile() const {
//  ci::gl::clear();
//  ci::gl::enableDepthRead();
//  ci::gl::enableDepthWrite();
//
//  auto lambert = ci::gl::ShaderDef().lambert();
//  auto shader = ci::gl::getStockShader(lambert);
//  shader->bind();
//  ci::gl::pushModelMatrix();
//  ci::vec3 sphere_pos = player_.GetPosition();
//
//  ci::gl::color(20,100,20);
//
//  ci::gl::drawSphere(sphere_pos, 1.0f, 80);
//  
//  ci::gl::popModelMatrix();
//}

const void GameEngine::DrawShapes() const {
  // Draw player
  ci::gl::clear();
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
  
//  cam.lookAt(player_.GetPosition(), vec3(0, 1, 0 ));
//  ci::gl::setMatrices(cam);
  // Draw projectiles
  for (const Projectile& projectile: projectiles_) {
    
    ci::gl::pushModelMatrix();

    ci::gl::color(20,100,20);
//    ci::gl::scale(projectile.GetScale());
    ci::gl::drawSphere(projectile.GetPosition(), projectile.GetRadius());

    ci::gl::popModelMatrix();
  }
}

void GameEngine::SpawnProjectile(const vec3& position) {
  Projectile projectile = Projectile(position);
  projectiles_.emplace_back(projectile);
}

void GameEngine::UpdateProjectiles() {
  for (Projectile &projectile: projectiles_) {
    projectile.MoveProjectileUp();
  }
  
  for (auto projectile = projectiles_.begin(); projectile != projectiles_.end(); ++projectile) {
    projectile->MoveProjectileUp();
    
    float erase_threshold = 5.0f;
    if (projectile->GetPosition().y > erase_threshold) {
      projectiles_.erase(projectile);
      --projectile;
    }
  }
  std::cout << projectiles_.size() << std::endl;
}

const size_t GameEngine::ProjectilesOnScreen() const {
  return projectiles_.size();
}

}
