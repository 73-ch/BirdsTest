//
//  Bird.hpp
//  Boids
//
//  Created by Kosaku Namikawa on 2020/04/07.
//

#ifndef Bird_hpp
#define Bird_hpp

#include <stdio.h>
#include "ofMain.h"

class Bird {
public:
    Bird(vector<Bird>&, const int, ofColor, vector<Bird>&, vector<Bird>&);
    virtual ~Bird();
    
    virtual void update();
    virtual void draw() const;
    int id;
    float head;
    float tail;
    glm::vec2 pos;
    glm::vec2 vel;
    glm::vec2 acc;
    ofColor color;
    
protected:
    vector<Bird>& selfGroup;
    vector<Bird>& enemyGroup;
    vector<Bird>& friendGroup;

    glm::vec2 separationVel;
    glm::vec2 alignmentVel;
    glm::vec2 cohesionVel;
    glm::vec2 groupCenterPos;
    
private:
    int cohesionCount;
    void runAlgorithmOnGroup(vector<Bird>&, const float);

};


#endif /* Bird_hpp */
