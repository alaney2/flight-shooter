#include "game_engine.h"

using ci::vec3;

namespace flightshooter {

GameEngine::GameEngine() {
  player_.SetPosition(ci::vec3(0));
}

const void GameEngine::Display() const {
  DrawPlayer();
  
}

void GameEngine::AdvanceOneFrame() {
  
}

Player GameEngine::ModifyPlayer() const {
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

}
