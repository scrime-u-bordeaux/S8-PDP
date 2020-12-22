/**
 *  \file    SampleData.h
 *  \author  Victor ZAPPI
 *  \date    Nov 5, 2014
 *
 *  \brief Fichier contenant la structure SampleData.
 *
 *  User defined structure to pass between main and rendere complex data
 *  retrieved from file
 *
 */

#ifndef SAMPLEDATA_H
#define SAMPLEDATA_H

/**
 *  \struct SampleData
 *  \brief Object composed by samples.
 */
struct SampleData {
	/**
	 * \var samples 	Samples in file
	 * \var sampleLen Total nume of samples
	 */
	float *samples;
	int sampleLen;
};

#endif // SAMPLEDATA_H
