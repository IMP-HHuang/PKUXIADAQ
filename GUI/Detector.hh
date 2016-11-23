#ifndef DETECTOR_HH_
#define DETECTOR_HH_

#include "../software/app/pixie16app_export.h"

#include <fcntl.h>
#include <semaphore.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <cstdio>
#include <fstream>
#include <iostream>

#define BLEN (500*2516) // size of 1 buffer
#define BUFFLENGTH (500*2516) // 4.8MB Buffer *2 (DBUFF)
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class Detector
{
public:
  Detector();
  virtual ~Detector();
  
  int Syncronise();
  int ExitSystem();
  int StartLSMRun(int continue_run);
  int OpenSaveFile(int n,const char *FileN);
  int SavetoFile(int nFile);
  int RunStatus();
  int ReadDataFromModules(int thres=0,unsigned short endofrun=0);
  int StopLSMRun();
  int CloseFile();
  int SetOnlineF(bool flag);
  int SaveHistogram(char *fileN,int mod);
  int OpenSharedMemory();
  int UpdateSharedMemory();
  void SetRunNumber(int r);
  unsigned int GetFileSize(int n); // in MB
  bool SetEvtl();
  //  	int Write2FileLSM(char *name);
  int AcquireADCTrace(unsigned short *trace, unsigned long size,
		       unsigned short module, unsigned short ChanNum);

  bool BootSystem();

  void StatisticsForModule();

public:
  unsigned short NumModules;
  
private:
  unsigned short *PXISlotMap;
  unsigned short OfflineMode;
  char ComFPGAConfigFile[256];
  char SPFPGAConfigFile[256];
  char TrigFPGAConfigFile[256];
  char DSPCodeFile[256];
  char DSPParFile[256];
  char DSPVarFile[256];
  bool ReadConfigFile(char *config = (char*)"../parset/cfgPixie16.txt");
	
  FILE *fsave[PRESET_MAX_MODULES];
  unsigned int buff[PRESET_MAX_MODULES][BUFFLENGTH];
  int buffid[PRESET_MAX_MODULES];
  unsigned long FILESIZE[PRESET_MAX_MODULES];
  unsigned int  *evtlen;// GOTO  in dan't fixed length

  // variables for shared memory
  sem_t *shmsem; // shared memory semaphore
  int    shmfd;  // shared memory id
  unsigned char *shmptr;// pointer to shm
  bool   fonline;
  int runnumber;
  //  	bool BootSystem (unsigned short NumModules, unsigned short *PXISlotMap);

  uint64_t CurrentTime;
  uint64_t PrevRateTime;
  uint64_t ElapsedTime;
  uint64_t StartTime;
  uint64_t StopTime;
  long get_time();
};

#endif /*DETECTOR_HH_*/