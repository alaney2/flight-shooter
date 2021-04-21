#include "game_engine.h"

using ci::vec3;

namespace flightshooter {

GameEngine::GameEngine() {
  
}

void GameEngine::Display() const {
  ci::gl::clear();
  ci::gl::enableDepthRead();
  ci::gl::enableDepthWrite();
  
  ci::CameraPersp cam;
  cam.lookAt( vec3( 0, 3, 3 ), vec3( 0,1,0));
  ci::gl::setMatrices(cam);

  auto lambert = ci::gl::ShaderDef().lambert();
  auto shader = ci::gl::getStockShader(lambert);
  shader->bind();
  
  ci::gl::drawCube( vec3(), player_.GetScale());

  ci::gl::setMatricesWindow(ci::app::getWindowSize());
  ci::gl::translate(100, 0);
}

void GameEngine::AdvanceOneFrame() {
  
}

Player GameEngine::ModifyPlayer() const {
  return player_;
}

}
