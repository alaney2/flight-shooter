#include "game_engine.h"
#include "cinder/gl/gl.h"

using ci::vec3;

namespace flightshooter {

GameEngine::GameEngine() {
  
}

void GameEngine::Display() const {
  ci::gl::clear();
  ci::gl::enableDepthRead();
  ci::gl::enableDepthWrite();
  
  
  ci::CameraPersp cam;
  cam.lookAt( vec3( 0, 3, 3 ), vec3( 0,0.8,0) );
  ci::gl::setMatrices(cam);

  auto lambert = ci::gl::ShaderDef().lambert();
  auto shader = ci::gl::getStockShader(lambert);
  shader->bind();
  
  ci::gl::drawCube( vec3(), vec3( 0.6) );
}

void GameEngine::AdvanceOneFrame() {
  
}
void GameEngine::StrafeDirection(char direction) {
  
}

}
