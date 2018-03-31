#ifndef PREPROCENERGY_HPP
#define PREPROCENERGY_HPP

#include <vector>

#include "EnergyProcess.hpp"
#include "../../Matrix.hpp"

using namespace std;

vector<float> energyenvelope(const vector<float>& f1, int frame);
extern "C" Matrix<float> PreprocEnergy(const Matrix<float>& input);

#endif // PREPROCENERGY_HPP
