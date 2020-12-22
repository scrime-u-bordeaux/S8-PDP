#include "CoeffInterCorrel.hpp"
#include <stdio.h>
#include <iostream>
#include <fftw3.h>
#include <complex>
#include <complex.h>
#include <algorithm>
#include <fstream>
using namespace std;
fftw_plan plan1;
fftw_plan plan2;
fftw_plan iplan;

// IFFT
void
ifft_init (complex<double>* in, complex<double>* out, int size)
{
  iplan = fftw_plan_dft_1d (size, reinterpret_cast<fftw_complex *>(in), reinterpret_cast<fftw_complex *>(out), FFTW_BACKWARD, FFTW_ESTIMATE);
}

void
ifft_exit (void)
{
  fftw_destroy_plan (iplan);
}

void
ifft_process (void)
{
  fftw_execute (iplan);
}

// FFT
/*void
fft_init (complex<double>* in, complex<double>* out, int size)
{
    plan = fftw_plan_dft_1d (size, reinterpret_cast<fftw_complex *>(in), reinterpret_cast<fftw_complex *>(out), FFTW_FORWARD, FFTW_ESTIMATE);
}

void
fft_exit (void)
{
    fftw_destroy_plan (plan);
}

void
fft_process (void)
{
    fftw_execute (plan);
}*/

extern "C"{
  vector<float> CoeffCorrel(const vector<float>& s1, const vector<float>& s2)
  {

    int size = s1.size();

    //Normalisation

    float max ;

  /*
      // Inter-correlation in time space
      int tau;
      int sz = max(s1.size(), s2.size());
      vector<float> correl(sz);

      for(tau=0; tau<sz; tau++) {
          correl[tau] = 0.0;

          for (size_t i = 0; i < sz; i++) {
              correl[tau] += s1[i] * s2[i - tau];
          }
      }
      return  correl;*/

    vector<float> correl(size*2-1);
    complex<double>* in_s1, *in_s2, *out_s1, *out_s2;
    complex<double>* c;
    complex<double>* correlComplex;
    c = (complex<double>*) fftw_malloc(sizeof(complex<double>)*(size*2-1));
    correlComplex = (complex<double>*) fftw_malloc(sizeof(complex<double>)*(size*2-1));
    in_s1 = (complex<double>*) fftw_malloc(sizeof(complex<double>)*(size*2-1));
    out_s1 = (complex<double>*) fftw_malloc(sizeof(complex<double>)*(size*2-1));
    in_s2 = (complex<double>*) fftw_malloc(sizeof(complex<double>)*(size*2-1));
    out_s2 = (complex<double>*) fftw_malloc(sizeof(complex<double>)*(size*2-1));

    for(int i = 0; i< size*2-1; i++)
    {
      in_s1[i] = in_s2[i] = out_s1[i] = out_s2[i] = c[i] = correlComplex[i] = 0;
    }

    for(int i = 0; i<size; i++)
    {
            in_s1[i].real(s1[i]);
            in_s2[size+i-1].real(s2[i]);
    }

    plan1 = fftw_plan_dft_1d (size*2-1 , reinterpret_cast<fftw_complex *>(in_s1), reinterpret_cast<fftw_complex *>(out_s1), FFTW_FORWARD, FFTW_ESTIMATE);
    plan2 = fftw_plan_dft_1d (size*2-1 , reinterpret_cast<fftw_complex *>(in_s2), reinterpret_cast<fftw_complex *>(out_s2), FFTW_FORWARD, FFTW_ESTIMATE);

    // Compute the FFT of s1
    fftw_execute(plan1);

    // Compute the FFT of s2
    fftw_execute(plan2);


  // Compute correlation
    for(int i = 0; i< size*2-1;i++)
    {
       c[i] = out_s1[i]*conj(out_s2[i]);
    }
    ifft_init(c, correlComplex, size*2-1);
    ifft_process();
  // Take real part of the correlation to return
    for(int i = 0; i < size*2-1; i++) {
        correl[i] = real(correlComplex[i])*(1.0/(size*2-1));
    }

    max = *max_element(correl.begin(), correl.end());
    // fft_exit();
    fftw_destroy_plan(plan1);
    fftw_destroy_plan(plan2);
    ifft_exit();
    fftw_free(in_s1); fftw_free(in_s2); fftw_free(out_s1); fftw_free(out_s2);
    fftw_free(c); fftw_free(correlComplex);
    return correl;
  }
}
vector<float> CoeffInterCorrel(const vector<float>& s1, const vector<float>& s2)
{
  vector<float> correls1 =  CoeffCorrel(s1,s1);
  vector<float> correls2 =  CoeffCorrel(s2,s2);
  vector<float> correl =  CoeffCorrel(s1,s2);

  float max1 = *max_element(correls1.begin(), correls1.end());
  float max2 = *max_element(correls2.begin(), correls2.end());
  for(int i = 0 ; i < correl.size(); i++)
  {
    correl[i] = correl[i]/ sqrt(max1 * max2);
  }
  return correl;
}
