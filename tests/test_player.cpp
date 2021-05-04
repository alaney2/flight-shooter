#include <catch2/catch.hpp>
#include "player.h"

namespace flightshooter {
TEST_CASE("Strafe") {
  Player player;
  player.SetPosition(ci::vec3(0));

  SECTION("Strafe left") {
    player.Strafe('a');
    REQUIRE(player.GetPosition().x == -0.045f);
    REQUIRE(player.GetPosition().y == 0);
    REQUIRE(player.GetPosition().z == 0);
  }

  SECTION("Strafe right") {
    player.Strafe('d');
    REQUIRE(player.GetPosition().x == 0.045f);
    REQUIRE(player.GetPosition().y == 0);
    REQUIRE(player.GetPosition().z == 0);
  }
}
TEST_CASE("Update position") {
  Player player;
  player.SetPosition(ci::vec3(0));
  
  SECTION("Moving left") {
    player.SetMovingLeft(true);
    player.UpdatePosition();
    
    REQUIRE(player.GetPosition().x == -0.045f);
    REQUIRE(player.GetPosition().y == 0);
    REQUIRE(player.GetPosition().z == 0);
  }

  SECTION("Moving right") {
    player.SetMovingRight(true);
    player.UpdatePosition();
    
    REQUIRE(player.GetPosition().x == 0.045f);
    REQUIRE(player.GetPosition().y == 0);
    REQUIRE(player.GetPosition().z == 0);
  }
}
}