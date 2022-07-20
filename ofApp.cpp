#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetColor(255);
	ofNoFill();
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(ofMap(sin(ofGetFrameNum() * 2 * DEG_TO_RAD), -1, 1, 255, 285));

	ofDrawRectangle(-300, -300, 600, 600);

	for (int i = 0; i < 6; i++) {

		vector<glm::vec3> vertices;
		auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(360));
		for (int k = 0; k < 70; k++) {

			auto x = ofMap(ofNoise(noise_seed.x, k * 0.005 + ofGetFrameNum() * 0.005), 0, 1, -300, 300);
			auto y = ofMap(ofNoise(noise_seed.y, k * 0.005 + ofGetFrameNum() * 0.005), 0, 1, -300, 300);
			auto z = ofMap(sin(((int)noise_seed.z + k + ofGetFrameNum()) * 4 * DEG_TO_RAD), -1, 1, -100, 100);

			vertices.push_back(glm::vec3(x, y, z));

			if (z < 3 && z > -3) {

				ofDrawCircle(glm::vec3(x, y, 0), 10);
			}
		}

		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(false);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}