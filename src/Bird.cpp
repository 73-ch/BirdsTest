//
//  Bird.cpp
//  Boids
//
//  Created by Kosaku Namikawa on 2020/04/07.
//

#include "Bird.hpp"

Bird::Bird(vector<Bird>& _selfGroup, const int _id, ofColor _color, vector<Bird>& _enemyGroup, vector<Bird>& _friendGroup) :
    selfGroup(_selfGroup),
    enemyGroup(_enemyGroup),
    friendGroup(_friendGroup),
    id(_id),
    color(_color){
    pos = glm::vec2(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    vel = glm::vec2(ofRandom(-2,2), ofRandom(-2,2));
    head = 2;
    tail = head * 4.;
};

Bird::~Bird() {
}


void Bird::update() {
    cohesionCount = 0;
    separationVel = glm::vec2(0);
    alignmentVel = glm::vec2(0);
    cohesionVel = glm::vec2(0);
    groupCenterPos = glm::vec2(0);
    
    runAlgorithmOnGroup(selfGroup, 10);
    // runAlgorithmOnGroup(friendGroup, 10);
    // runAlgorithmOnGroup(enemyGroup, 60);

    // ofLogNotice() << separationVel;
    separationVel = glm::length(separationVel) > 0 ? glm::normalize(separationVel) : separationVel;
    alignmentVel = glm::length(alignmentVel) > 0 ? glm::normalize(alignmentVel) : alignmentVel;

    // groupCenterPos /= cohesionCount;
    cohesionVel = glm::length(groupCenterPos) > 0 ? glm::normalize(groupCenterPos / cohesionCount - pos) : glm::vec2(0);
    ofLogNotice() << cohesionVel;
    vel += separationVel * 0.15 + alignmentVel * 0.035 + cohesionVel * 0.02;
    
    vel = normalize(vel) * 0.15;
    pos += vel;

    if (glm::abs(pos.x - ofGetWidth() * 0.5) > ofGetWidth() * 0.5) {
        vel.x *= -1;
    }
    if (glm::abs(pos.y - ofGetHeight() * 0.5) > ofGetHeight() * 0.5) {
        vel.y *= -1;
    }
    
}

void Bird::draw() const {
    ofSetColor(color);
    ofDrawCircle(pos, head);
    ofDrawLine(pos + vel * tail * 0.5, pos - vel * tail);
}

void Bird::runAlgorithmOnGroup(vector<Bird>& group, const float nearest) {
    for (auto& target : group) {
        if (target.id == id) continue;
        float dist = glm::distance(pos, target.pos);
        if (dist < nearest) {
            separationVel += pos - target.pos;
        } else if (dist < 35) {
            alignmentVel += target.vel;
        } else if (dist < 60) {
            groupCenterPos += target.pos;
            cohesionCount++;
        }
    }
}
