#include <catch2/catch.hpp>
#include "flight_shooter_app.h"
#include "game_engine.h"

namespace flightshooter {
TEST_CASE("Spawn projectile") {
  GameEngine engine;
  ci::vec3 projectile_position(1,2,3);
  engine.SpawnProjectile(projectile_position);

  REQUIRE(engine.ProjectilesOnScreen() == 1);
  REQUIRE(engine.GetProjectiles()[0].GetPosition().x == 1);
  REQUIRE(engine.GetProjectiles()[0].GetPosition().y == 2);
  REQUIRE(engine.GetProjectiles()[0].GetPosition().z == 3);
}

TEST_CASE("Spawn enemy") {
  GameEngine engine;
  ci::vec3 enemy_position(1,2,3);
  engine.SpawnEnemy(enemy_position);

  REQUIRE(engine.GetEnemies().size() == 1);
  REQUIRE(engine.GetEnemies()[0].GetPosition().x == 1);
  REQUIRE(engine.GetEnemies()[0].GetPosition().y == 2);
  REQUIRE(engine.GetEnemies()[0].GetPosition().z == 3);
}

TEST_CASE("Update projectiles") {
  GameEngine engine;
  ci::vec3 projectile_position(1,2,3);
  engine.SpawnProjectile(projectile_position);
  
  
}
}