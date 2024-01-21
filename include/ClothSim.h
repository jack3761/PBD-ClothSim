#ifndef CLOTHSIM_H_
#define CLOTHSIM_H_

#include <ngl/Vec3.h>
#include "ClothMesh.h"

class ClothSim
{
public:
    ClothSim()=default;
    ClothSim(float _gravity, ngl::Vec3 _wind, size_t _timeStep, size_t _solveIterations);
    ClothSim(float _cWidth, float _cHeight, size_t _pWidth, size_t _pHeight);
    ClothSim(float _gravity, ngl::Vec3 _wind, size_t _timeStep, size_t _solveIterations, float _cWidth, float _cHeight, size_t _pWidth, size_t _pHeight);

    void runSim(float _delta);
    void createNewMesh(float _cWidth, float _cHeight, size_t _pWidth, size_t _pHeight);
    void initialise();
    void initFixedPoints();
    void solveConstraints();
    float getGravity() const;
    ngl::Vec3 getWind() const;
    size_t getTimeStep() const;
    size_t getIterations() const;
    void setGravity(float _gravity);
    void setWind(ngl::Vec3 _wind);
    void setFixedPoint(size_t i, bool fixed);
    ClothMesh mesh;

private:
    float gravity = -9.81f;
    ngl::Vec3 wind = {0.0, 0.0, 1.0};
    size_t timeStep = 1;
    size_t solveIterations = 1000;
    size_t numParticles;
    bool fixedPoints[6];

};

#endif
