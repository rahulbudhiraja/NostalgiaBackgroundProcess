#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main(int argc,char *argv[] ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1024,768, OF_FULLSCREEN);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
    
    if(argc<2)
    {
        cout<<"Too Few Arguements\n";
        ofExit();
    }
    
    char *test;
    
    long long int uid=strtoll(argv[1], &test, 10);
    cout<<endl<<uid;
	ofRunApp( new testApp(uid));

}
