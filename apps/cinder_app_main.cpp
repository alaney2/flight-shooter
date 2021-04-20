#include "flight_shooter_app.h"

using flightshooter::TPShooterApp;

void prepareSettings(TPShooterApp::Settings* settings) {
  settings->setResizable(false);
}

CINDER_APP(TPShooterApp, ci::app::RendererGl, prepareSettings);