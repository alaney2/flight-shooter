#include "tpshooter_app.h"

using tpshooter::TPShooterApp;

void prepareSettings(TPShooterApp::Settings* settings) {
  settings->setResizable(false);
}

CINDER_APP(TPShooterApp, ci::app::RendererGl, prepareSettings);