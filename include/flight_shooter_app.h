#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_engine.h"
#include "common.h"

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
  size_t score_ = 0;
  const size_t kMaxProjectiles_ = 5;
  const int kWindowWidth_ = 720;
  const int kWindowLength_ = 720;
};
}
