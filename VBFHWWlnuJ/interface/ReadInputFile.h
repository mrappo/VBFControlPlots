#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


int ReadInputSampleFile   (const std::string & ,std::vector<std::string> &, std::vector<std::string> &, std::vector<int> &,  std::vector<double> &, std::vector<int> &);

int ReadInputVariableFile (const std::string & ,std::vector<std::string> &, std::vector<int> &, std::vector<double> & ,std::vector<double> & );

int ReadInputCutFile      (const std::string & ,std::vector<std::string> &);
