#include <catch2/catch.hpp>
#include "enemy.h"

namespace flightshooter {

TEST_CASE("Move enemy down") {
  glm::vec3 position(0, 0, 0);
  Enemy enemy(position);
  enemy.MoveEnemyDown(0.5);
  
  REQUIRE(enemy.GetPosition().x == 0);
  REQUIRE(enemy.GetPosition().y == -0.5);
  REQUIRE(enemy.GetPosition().z == 0);
}
}
