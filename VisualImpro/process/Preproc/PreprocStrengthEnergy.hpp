#ifndef PREPROCSTRENGTHENERGY_HPP
#define PREPROCSTRENGTHENERGY_HPP

#include <vector>

#include "EnergyProcess.hpp"
#include "../../Matrix.hpp"

using namespace std;

vector<float> strengthenergyenvelope(const vector<float>& f1, int frame);
extern "C" Matrix<float> PreprocStrengthEnergy(const Matrix<float>& input);

#endif // PREPROCSTRENGTHENERGY_HPP
