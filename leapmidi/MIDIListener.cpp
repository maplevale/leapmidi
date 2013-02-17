/*
 *  MIDIListener.cpp
 *  LeapMIDI
 *
 *  Created by Mischa Spiegelmock on 11/28/12.
 *  Copyright (c) 2012 int80. All rights reserved.
 *
 */

#include "MIDIListener.h"

namespace leapmidi {
    
Listener::Listener() {
    currentProgram = NULL;
}


void Listener::onFrame(const Leap::Controller &controller) {
    if (! currentProgram) return;
    
    // use current active gesture recognizers to locate gestures
    // and controls in this frame.
    // will call onGestureRecognized and onControlUpdated if appropriate
    currentProgram->findControls(controller, *this);
}

// do something productive with these in your application's Listener subclass
void Listener::onInit(const Leap::Controller& controller) {}
void Listener::onConnect(const Leap::Controller& controller) {}
void Listener::onDisconnect(const Leap::Controller& controller) {}
void Listener::onGestureRecognized(const Leap::Controller &controller, GesturePtr gesture) {}
void Listener::onControlUpdated(const Leap::Controller &controller, GesturePtr gesture, ControlPtr control) {}
    
}
