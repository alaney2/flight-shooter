#include "flight_shooter_app.h"

using flightshooter::FlightShooter;

void prepareSettings(FlightShooter::Settings* settings) {
  settings->setResizable(false);
}

CINDER_APP(FlightShooter, ci::app::RendererGl, prepareSettings);