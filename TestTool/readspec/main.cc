// main.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 日 10月  2 19:01:31 2016 (+0800)
// Last-Updated: 四 1月 31 19:42:28 2019 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 13
// URL: http://wuhongyi.cn 

#include "readfile.hh"
#include "UserDefine.hh"

#include "TString.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

int main(int argc, char *argv[])
{
  if(argc != 2)
    {
      std::cout<<"error(argc != 2)      "<<argv[0]<<" [RunNumber]"<<std::endl;
      return 0;
    }

  TString RunNumber(argv[1]);
  int  runnumber = RunNumber.Atoi();

  readfile *r2r = new readfile(runnumber);
  r2r->Process();
  delete r2r;
  
  return 0;
}

// 
// main.cc ends here