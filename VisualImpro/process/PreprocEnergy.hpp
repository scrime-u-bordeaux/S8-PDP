#ifndef PREPROCENERGY_HPP
#define PREPROCENERGY_HPP

#include <vector>

using namespace std;

float energy(const vector <float>& f1, int start, int end);
vector<float> energyenvelope(const vector<float>& f1, int frame);
extern "C" Matrix<float> PreprocEnergy(const Matrix<float>& input);

#endif // PREPROCENERGY_HPP
