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

const void GameEngine::ShootProjectile() const {
  ci::gl::clear();
  ci::gl::enableDepthRead();
  ci::gl::enableDepthWrite();

  auto lambert = ci::gl::ShaderDef().lambert();
  auto shader = ci::gl::getStockShader(lambert);
  shader->bind();
  ci::gl::pushModelMatrix();
  ci::vec3 sphere_pos = player_.GetPosition();

  ci::gl::color(20,100,20);

  ci::gl::drawSphere(sphere_pos, 1.0f, 80);
  
  ci::gl::popModelMatrix();
}

const void GameEngine::DrawShapes() const {
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

  ci::gl::pushModelMatrix();
  ci::vec3 sphere_pos = player_.GetPosition();

  ci::gl::color(20,100,20);

  ci::gl::drawSphere(sphere_pos, 0.3f, 10);

  ci::gl::popModelMatrix();
}

void GameEngine::SpawnProjectile(const vec3& position) {
  Projectile projectile = Projectile(position);
  projectiles_.emplace_back(projectile);
}

}
