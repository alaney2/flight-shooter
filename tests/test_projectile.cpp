#include <catch2/catch.hpp>
#include "projectile.h"

namespace flightshooter {
TEST_CASE("Move projectile up") {
  glm::vec3 position(0,0,0);
  Projectile projectile(position);
  projectile.MoveProjectileUp();
  
  REQUIRE(projectile.GetPosition().x == 0);
  REQUIRE(projectile.GetPosition().y == 0.06f);
  REQUIRE(projectile.GetPosition().z == 0);
}
}
