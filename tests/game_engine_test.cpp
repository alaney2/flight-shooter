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

  SECTION("Projectile moving up") {
    ci::vec3 projectile_position(1, 2, 3);
    engine.SpawnProjectile(projectile_position);
    engine.UpdateProjectiles();

    REQUIRE(engine.GetProjectiles()[0].GetPosition().x == 1);
    REQUIRE(engine.GetProjectiles()[0].GetPosition().y == 2.06f);
    REQUIRE(engine.GetProjectiles()[0].GetPosition().z == 3);
  }

  SECTION("Projectile out of bounds") {
    ci::vec3 projectile_position(0, 3.1, 0);
    engine.SpawnProjectile(projectile_position);
    REQUIRE(engine.GetProjectiles().size() == 1);
    engine.UpdateProjectiles();
    REQUIRE(engine.GetProjectiles().size() == 0);
  }

  SECTION("Projectile directly collides with enemy") {
    ci::vec3 projectile_position(0, 2, 0);
    engine.SpawnProjectile(projectile_position);
    REQUIRE(engine.GetProjectiles().size() == 1);
    
    ci::vec3 enemy_position(0,2,0);
    engine.SpawnEnemy(enemy_position);
    REQUIRE(engine.GetEnemies().size() == 1);
    
    engine.UpdateProjectiles();

    REQUIRE(engine.GetProjectiles().size() == 0);
    REQUIRE(engine.GetEnemies().size() == 0);
  }

  SECTION("Projectile collides at enemy boundary") {
    ci::vec3 projectile_position(0, 2, 0);
    engine.SpawnProjectile(projectile_position);

    ci::vec3 enemy_position(0.29,2,0);
    engine.SpawnEnemy(enemy_position);

    engine.UpdateProjectiles();

    REQUIRE(engine.GetProjectiles().size() == 0);
    REQUIRE(engine.GetEnemies().size() == 0);
  }
}

TEST_CASE("Update enemies") {
  GameEngine engine;
  
  SECTION("Enemy moving down") {
    ci::vec3 enemy_position(1,2,3);
    engine.SpawnEnemy(enemy_position);
    engine.UpdateEnemies();

    REQUIRE(engine.GetEnemies()[0].GetPosition().x == 1);
    REQUIRE(engine.GetEnemies()[0].GetPosition().y == 1.98f);
    REQUIRE(engine.GetEnemies()[0].GetPosition().z == 3);
  }

  SECTION("Game over") {
    REQUIRE(engine.IsGameOver() == false);

    ci::vec3 enemy_position(0,-1,0);
    engine.SpawnEnemy(enemy_position);
    engine.UpdateEnemies();

    REQUIRE(engine.IsGameOver() == true);
  }
}
}