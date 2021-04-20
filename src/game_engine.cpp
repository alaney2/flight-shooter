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
  cam.lookAt( vec3( 0, 3, 3 ), vec3( 0,0.5,0));
  ci::gl::setMatrices(cam);

  auto lambert = ci::gl::ShaderDef().lambert();
  auto shader = ci::gl::getStockShader(lambert);
  shader->bind();
  
  ci::gl::drawCube( vec3(), vec3( 0.6) );

  ci::gl::setMatricesWindow(ci::app::getWindowSize());
  ci::gl::translate(100, 0);
}

void GameEngine::AdvanceOneFrame() {
  
}

void GameEngine::StrafeDirection(char direction) {
  if (direction == 'd') {
    
  }
  if (direction == 'a') {
    
  }
}

}
