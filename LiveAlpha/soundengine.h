
#ifndef SOUNDENGINE
#define SOUNDENGINE

#include <vector>
#include <sndfile.h>

#include "blackbox.h"
#include "grainengine.h"


using std::vector;


class Track {


 public:

  Track( int samplerate,
	 int tempo,
	 int numdivs,
	 int laststep,
	 int grainsizems,
	 int sfsamplerate,
	 int sflength,
	 float *sfdata ); 


  int Step( int inc );

  int SetStep( int step );

  int SetNumDivs( int numdivs );

  int SetLastStep( int laststep );

  int SetTempo( int tempo );


  Phasor* PlayerPhase;

  GrainEngine* Player;

  bool IsLoopMode;


  int CurrentStep;

  int NextStep;

  int StartStep;

  int LastStep;

  int StepSkip;

  int SkipCount;

  int Divisions;
  

 protected:

  int sr;

  int tempo;


  float *data;

  int datalen;

  int datasr;


};


class SoundEngine : public BlackBox {


 public:

  SoundEngine( int samplerate,
	       int tempo,
	       int maxsteps,
	       int maxrecbuflenseconds,
	       int defaultgrainsizems );

  float Process();

  Track* NewTrack( char *soundfile );

  int SetTempo( int bpm );

  vector<Track*> Tracks;


 protected:

  int sr; //sample rate

  int tempo;

  int maxsteps;

  int defaultgrainsize;

 
  double trackstepphase;


  int recbuflen;

  float* recbuf;

  float* recbackbuf;

  

};


#endif SOUNDENGINE
