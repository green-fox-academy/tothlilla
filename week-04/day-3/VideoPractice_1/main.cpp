#include <iostream>

class fridge
{
 protected:
  bool HasFreon;
 public:
  int Temp;
};
class truck
{
 private:
  int Gas; //alapesetben ez private és nem látja a derived class
 public:
  int Speed;
  void setGas(int mGas){
    Gas = mGas;
  }
  int getGas(){ //ezzel tudok visszahatni a private member Gas-re
    return Gas + 30;
  }
};
class freezetruck : public truck, public fridge
{
 public:
  void setFreon(){
    this-> HasFreon = true;
  }
};
int main() {
  freezetruck mTruck;

  mTruck.Speed = 100;
  mTruck.Temp = 20;

  std::cout << mTruck.Speed << std::endl;
  std::cout << mTruck.Temp << std::endl;
  std::cout << "\n" << std::endl;

  //ez az eset nem működik, mert a Gas private member
  //mTruck.setGas(500);
  //std::cout << mTruck.Gas << std::endl;

  mTruck.setGas(500); //a Gas helyére 500 kerül
  std::cout << mTruck.getGas() << std::endl;
  std::cout << "\n" << std::endl;

  //mTruck.HasFreon = true; //alapesetben nem működik, mert private function
  mTruck.setFreon();
  //std::cout << mTruck.setFreon() << std::endl; nem lehet kiprintelni!
  return 0;
}