#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "game_engine.h"

namespace tpshooter {

class TPShooterApp : public ci::app::App {
 public:
  TPShooterApp();
  void draw() override;
  void update() override;
  void keyDown(cinder::app::KeyEvent event) override;

 private:
  GameEngine engine;

  const int kWindowWidth_ = 1280;
  const int kWindowLength_ = 720;
};
}
