#include <iostream>
#include <fstream>
using namespace std;

int main() {
  // Create and open a text file
  ifstream ip("csv_updated.csv");

  // Write to the file
  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

  string gender;
  string age;
  string smoking;
  string yellow_fingers;
  string fatigue;
  string coughing;
  string chest_pain;
  string lung_cancer;


  while(ip.good()){

    getline(ip,gender,';');
    getline(ip,age,';');
    getline(ip,smoking,';');
    getline(ip,yellow_fingers,';');
    getline(ip,fatigue,';');
    getline(ip,coughing,';');
    getline(ip,chest_pain,';');
    getline(ip,lung_cancer,'\n');

    std::cout << "gender: "<<gender<< '\n';
    std::cout << "Age: "<<age << '\n';
    std::cout << "smoking: "<<smoking << '\n';
    std::cout << "yellow fingers: "<<yellow_fingers << '\n';
    std::cout << "fatigue: "<<fatigue << '\n';
    std::cout << "coughing: "<<coughing << '\n';
    std::cout << "chest pain: "<<chest_pain << '\n';
    std::cout << "lung cancer: "<<lung_cancer << '\n';
    std::cout << "-------------------" << '\n';
  }

  ip.close();
}