#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_engine.h"

namespace flightshooter {

class FlightShooter : public ci::app::App {
 public:
  FlightShooter();
  void draw() override;
  void update() override;
  void keyDown(cinder::app::KeyEvent event) override;
  void keyUp(cinder::app::KeyEvent event) override;

 private:
  GameEngine engine_;

  const int kWindowWidth_ = 720;
  const int kWindowLength_ = 840;
};
}
