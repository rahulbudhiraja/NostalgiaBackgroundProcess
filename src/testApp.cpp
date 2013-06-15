#include "testApp.h"

//--------------------------------------------------------------

testApp::testApp(long long int uid)
{
    userid=uid;
    
        
   
    
}
void testApp::setup()
{
    ofHideCursor();
    udpConnection.Create();
	udpConnection.Bind(12001);
	udpConnection.SetNonBlocking(true);
    SplashScreen.loadImage("NostalgiaRoom.tif");
    ofSetFullscreen(true);
    previewText.loadFont("asyouwish.ttf", 42);
}

//--------------------------------------------------------------
void testApp::update()
{
	char udpMessage[100000];
	udpConnection.Receive(udpMessage,100000);
	string message=udpMessage;
    
	if(message!="") 
    {
        // Check if there is an existing user in the Room (if the process is running)        
        string status=exec("ps -ax -o etime,command -c | grep Spiral_PrototypeDebug");
        
        
        // The udp message is processed only if another process is not running ...
        
        if(status.size()>=1)
            cout<<"Process is running ...";
        else {
            
        // Start a new one ..
        cout<<message<<endl;
        string messageToBeSent="open /Users/rahulbudhiraja/Work/of_v0073_osx_release/apps/myApps/Nostalgia_Spiral/bin/Spiral_PrototypeDebug.app --args "+message;
        system(messageToBeSent.c_str());
            
        }
        
        
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::draw()
{

    SplashScreen.draw(0,0);
    previewText.drawString("Lets take a swing at those memories,Have a seat !", 160, SplashScreen.getHeight()-25);
   
   
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}