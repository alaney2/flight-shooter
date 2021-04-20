#pragma once

namespace flightshooter {

class GameEngine {
 public:
  GameEngine();
  
  void Display() const;
  
  void AdvanceOneFrame();
  
  void StrafeDirection(char direction);
  
 private:
  
};

}
