#include "MediaPlayer.h"
#include "VoiceRecognizer.h"
#include "MainWindow.h"
#include "MouseGUI.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    MainWindow* mw = new MainWindow(&argc, &argv);
	MouseGUI* mg = new MouseGUI(mw->getWindow());

	mg->components();

    mw->init();
//    MediaPlayer* mp = new MediaPlayer();
//    VoiceRecognizer* vr = new VoiceRecognizer();
//
//    vr->run();

    //mp->playStream(mp->record());

    return 0;
}

